/**
 * tests/BitOps/String7_test.cpp
 */

#include <tests/BitOps/String7_test.h>
#include <BitOps/Istream.h>
#include <BitOps/Ostream.h>
#include <BitOps/String7.h>

namespace BitOps {

void String7_test::testRoutine() {
  String7 str("Aaron");
  requireEqual(str.toStr(), "Aaron");

  Ostream obuf;
  obuf << str;
  requireEqual(obuf.getBitPos(), 7 * (str.toStr().size() + 1) % 8);
  requireEqual(obuf.getBytePos(), 7 * (str.toStr().size() + 1) / 8);

  requireEqual(obuf.at(0), 0b1000'0011);
  requireEqual(obuf.at(1), 0b1000'0111);
  requireEqual(obuf.at(2), 0b1001'0110);
  requireEqual(obuf.at(3), 0b1111'1101);
  requireEqual(obuf.at(4), 0b1101'1111);
  requireEqual(obuf.at(5), 0b1100'0000);

  Istream ibuf(obuf.data(), obuf.size());
  String7 str2;
  ibuf >> str2;
  requireEqual(str.toStr(), str2.toStr());
}

}  // End namespace BitOps
