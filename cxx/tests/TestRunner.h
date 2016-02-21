/**
 * tests/TestRunner.h
 */

#ifndef TESTS_TESTRUNNER_H_
#define TESTS_TESTRUNNER_H_

#include <cxxabi.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <typeinfo>
#include <utility>
#include <include/OsCompatibility.h>
#include <tests/FailPrinter.h>
#include <Util/CommandLineOption.h>
#include <Util/Log.h>

namespace tests {

/*
 * Abstract class for unit tests to inherit from
 */
class TestRunner {
 public:
  typedef std::unique_ptr<TestRunner> Ptr;

  /**
   * Constructors
   */
  TestRunner() : _verbose(true), _subTests(), _successes(0), _fails(0) {}
  virtual ~TestRunner() = default;

  /**
   * Required interface definitions
   */
  virtual void testRoutine() = 0;

  /**
   * Utility template methods
   */
  template <typename T>
  void addTest() {
    _subTests.push_back(std::make_unique<T>());
  }

  template <typename T, typename U>
  void requireEqual(T t, U u) {
    bool testResult = (t == u);
    trackTest(testResult);
    if (!testResult) {
      FailPrinter<T, U> failPrinter(t, u);
      std::cout << failPrinter << std::endl;
    }
  }

  template <typename T, typename... Args>
  bool construct(Args&&... args) const {
    auto success = true;
    try {
      T _instance{std::forward<Args>(args)...};
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
      success = false;
    }
    return success;
  }

  template <typename T, typename... Args>
  void constructorTest(Args&&... args) {
    trackTest(construct<T>(std::forward<Args>(args)...));
  }

  char* demangleName(const std::type_info& id) const {
    int status;
    return abi::__cxa_demangle(id.name(), 0, 0, &status);
  }

  std::string getTestName() const {
    using uniq_string = std::unique_ptr<char, decltype(std::free)*>;
    std::string testName;
    uniq_string realname{demangleName(typeid(*this)), std::free};
    testName = realname.get();
    return testName;
  }

  std::string getEntryMsg() const {
    std::stringstream ss;
    ss << "***ENTER: " << CYAN_BG << getTestName() << CONSOLE_DEFAULT << " ***";
    return ss.str();
  }

  const char* getExitMsg() const { //
    return "*** EXIT ***";
  }

  virtual void setupSubTests() {}
  void setVerbosity(bool verbose) {
    _verbose = verbose;
  }

  void runMyTests() {
    if (_verbose) {
      std::cout << std::endl << getEntryMsg() << std::endl;
    }
    testRoutine();
    if (_verbose) {
      std::cout << getExitMsg() << std::endl;
    }
  }

  void runAllTests() {
    runMyTests();
    setupSubTests();
    for (auto& subTest : _subTests) {
      subTest->setVerbosity(_verbose);
      subTest->runAllTests();
    }
  }

  void runTests(std::string testName) {
    std::string fullTestName = getTestName();
    if (fullTestName.find(testName) != std::string::npos) {
      runMyTests();
    }
    setupSubTests();
    for (auto& subTest : _subTests) {
      subTest->setVerbosity(_verbose);
      subTest->runTests(testName);
    }
  }

  void markSuccess() { //
    ++_successes;
  }

  void markFail() { //
    ++_fails;
  }

  int getSuccesses() const {
    int subSuccesses = 0;
    for (auto& subTest : _subTests) {
      subSuccesses += subTest->getSuccesses();
    }
    return _successes + subSuccesses;
  }

  int getFails() const {
    int subFails = 0;
    for (auto& subTest : _subTests) {
      subFails += subTest->getFails();
    }
    return _fails + subFails;
  }

  void trackTest(bool testResult) {
    auto testNumber = _fails + _successes + 1;
    if (_verbose) {
      if (testNumber < 10) {
        std::cout << " ";
      }
      std::cout << testNumber << ": ";
    }

    if (testResult) {
      markSuccess();
      if (_verbose) {
        std::cout << GREEN_FG << "PASS" << CONSOLE_DEFAULT << std::endl;
      }
    } else {
      markFail();
      if (_verbose) {
        std::cout << RED_FG << "FAIL" << CONSOLE_DEFAULT;
      }
    }
  }

protected:
  bool _verbose;

private:
  std::vector<Ptr> _subTests;
  int _successes;
  int _fails;
};

}  // End namespace tests

#endif  // TESTS_TESTRUNNER_H_
