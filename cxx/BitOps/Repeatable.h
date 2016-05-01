/**
 * BitOps/Repeatable.h
 */

#ifndef BITOPS_REPEATABLE_H_
#define BITOPS_REPEATABLE_H_

#include <algorithm>
#include <vector>
#include <BitOps/Optional.h>
#include <BitOps/Ostream.h>
#include <BitOps/Istream.h>

namespace BitOps {

template <class T>
class Repeatable {
 public:
  Repeatable() = default;
  virtual ~Repeatable() = default;

  bool operator==(const Repeatable<T>& other) {
    return _blocks == other._blocks;
  }

  const T& at(std::uint32_t index) {
    return _blocks.at(index);
  }

  void push_back(const T& t) {
    _blocks.push_back(t);
  }

  std::size_t size() const {
    return _blocks.size();
  }

  friend Ostream& operator<<(Ostream& buf, Repeatable<T>& rep) {
    auto start = rep._blocks.begin();
    auto last = rep._blocks.end() - 1;
    auto writeBlock = [&buf](T& block) { buf << true << block; };
    std::for_each(start, last, writeBlock);
    return buf << false << *last;
  }

  friend Istream& operator>>(Istream& buf, Repeatable<T>& rep) {
    bool repeats = true;
    while (repeats) {
      T block;
      buf >> repeats >> block;
      rep.push_back(block);
    }
    return buf;
  }

 private:
  std::vector<T> _blocks;
};

}  // End namespace BitOps

#endif  // BITOPS_REPEATABLE_H_

