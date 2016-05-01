/**
 * tests/BitOps/Repeatable_test.cpp
 */

#include <tests/BitOps/Repeatable_test.h>
#include <BitOps/Repeatable.h>

namespace BitOps {

void Repeatable_test::testRoutine() {
  logTestCase(test1Int0);
  test1Int0();

  logTestCase(test1Int1);
  test1Int1();

  logTestCase(test2Int);
  test2Int();
}

void Repeatable_test::test1Int0() {
  const std::uint32_t arrsize = 5;
  std::uint8_t arr[arrsize] = {0, 0, 0, 0, 0};
  Istream ibuf(arr, arrsize);
  Repeatable<std::uint32_t> repeatedInt;

  ibuf >> repeatedInt;
  requireEqual(repeatedInt.size(), 1);
  requireEqual(repeatedInt.at(0), 0);
}

void Repeatable_test::test1Int1() {
  const std::uint32_t arrsize = 5;
  std::uint8_t arr[arrsize] = {0, 0b1000'0000, 0, 0, 0};
  Istream ibuf(arr, arrsize);
  Repeatable<std::uint32_t> repeatedInt;

  ibuf >> repeatedInt;

  requireEqual(repeatedInt.size(), 1);
  requireEqual(repeatedInt.at(0), 1);
}

void Repeatable_test::test2Int() {
  Repeatable<std::uint32_t> repeatIntOut;

  repeatIntOut.push_back(17);
  repeatIntOut.push_back(42);

  requireEqual(repeatIntOut.size(), 2);
  requireEqual(repeatIntOut.at(0), 17);
  requireEqual(repeatIntOut.at(1), 42);

  Ostream obuf;
  obuf << repeatIntOut;

  requireEqual(obuf.at(0), 136); // 1000 1000
  requireEqual(obuf.at(1), 128); // 1000 0000
  requireEqual(obuf.at(2), 0);   // 0000 0000
  requireEqual(obuf.at(3), 0);   // 0000 0000
  requireEqual(obuf.at(4), 10);  // 0000 1010
  requireEqual(obuf.at(5), 128); // 1000 0000
  requireEqual(obuf.at(6), 0);   // 0000 0000
  requireEqual(obuf.at(7), 0);   // 0000 0000
  requireEqual(obuf.at(8), 0);   // 0000 0000

  Istream ibuf(obuf.data(), obuf.size());
  Repeatable<std::uint32_t> repeatedIntIn;
  ibuf >> repeatedIntIn;

  requireEqual(repeatedIntIn.size(), 2);
  requireEqual(repeatedIntIn.at(0), 17);
  requireEqual(repeatedIntIn.at(1), 42);
}

}  // End namespace BitOps
