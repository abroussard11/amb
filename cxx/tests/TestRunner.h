/**
 * tests/TestRunner.h
 */

#ifndef TESTS_TESTRUNNER_H_
#define TESTS_TESTRUNNER_H_

#include <iostream>
#include <memory>
#include <typeinfo>
#include <utility>
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
  TestRunner() : _subTests(), _successes(0), _fails(0) {}
  virtual ~TestRunner() = default;

  /**
   * Required interface definitions
   */
  virtual const char* getTestName() const = 0;
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
      std::cout << "   Reason: [ " << std::boolalpha << t << " != " << u << " ]"
                << std::endl;
    }
  }

  template <typename T, typename... Args>
  void constructorTest(Args&&... args) {
    auto success = true;
    try {
      T _instance{std::forward<Args>(args)...};
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
      success = false;
    }

    trackTest(success);
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

  void runTests() {
    using std::cout;
    using std::endl;

    // Call this test
    cout << endl
         << "*** ENTER: " << CYAN_BG << getTestName() << CONSOLE_DEFAULT
         << " ***" << endl;

    testRoutine();

    cout << "*** EXIT ***" << endl;

    // Recursively call sub-tests
    for (auto& subTest : _subTests) {
      // TODO fork each subtest for isolation?
      subTest->runTests();
    }
  }

  void markSuccess() { ++_successes; }

  void markFail() { ++_fails; }

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
    using Util::Log;

    auto testNumber = _fails + _successes + 1;
    if (testNumber < 10) std::cout << " ";
    std::cout << testNumber << ": ";

    if (testResult) {
      markSuccess();
      std::cout << GREEN_FG << "PASS" << CONSOLE_DEFAULT << std::endl;
    } else {
      markFail();
      std::cout << RED_FG << "FAIL" << CONSOLE_DEFAULT << std::endl;
    }
  }

 private:
  std::vector<Ptr> _subTests;
  int _successes;
  int _fails;
};

}  // End namespace tests

#endif  // TESTS_TESTRUNNER_H_
