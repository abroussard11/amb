/**
 * tests/BitOps/BitOpsUnitTest.cpp
 */

#include <tests/BitOps/BitOpsUnitTest.h>
#include <tests/BitOps/Int_test.h>
#include <tests/BitOps/Istream_test.h>
#include <tests/BitOps/NyBitByte_test.h>
#include <tests/BitOps/Optional_test.h>
#include <tests/BitOps/Ostream_test.h>
#include <tests/BitOps/Repeatable_test.h>
#include <tests/BitOps/String7_test.h>
#include <BitOps/Istream.h>
#include <BitOps/NyBitByte.h>
#include <BitOps/Optional.h>
#include <BitOps/Ostream.h>
#include <BitOps/Repeatable.h>
#include <BitOps/String7.h>

namespace BitOps {

void BitOpsUnitTest::setupSubTests() {
  addTest<Int_test>();
  addTest<Istream_test>();
  addTest<NyBitByte_test>();
  addTest<Optional_test>();
  addTest<Ostream_test>();
  addTest<Repeatable_test>();
  addTest<String7_test>();
}

struct SampleMsg {
  std::uint16_t id;
  String7 name;
  Optional<NyBitByte<21>> importantNum;
  Repeatable<std::uint32_t> timestamps;

  friend Ostream& operator<<(Ostream& buf, SampleMsg& msg) {
    return buf << msg.id
               << msg.name
               << msg.importantNum
               << msg.timestamps;
  }

  friend Istream& operator>>(Istream& buf, SampleMsg& msg) {
    return buf >> msg.id
               >> msg.name
               >> msg.importantNum
               >> msg.timestamps;
  }
};

void BitOpsUnitTest::testRoutine() {
  SampleMsg msg;
  msg.id = 301;
  msg.name = String7("Sample");
  msg.importantNum.set(NyBitByte<21>(2097150));
  for (std::uint64_t i = 0; i < 4; i++) {
    msg.timestamps.push_back(4291000000 + i);
  }

  Ostream obuf;
  obuf << msg;

  SampleMsg msgIn;
  Istream ibuf(obuf.data(), obuf.size());
  ibuf >> msgIn;

  requireEqual(msgIn.id, msg.id);
  requireEqual(msgIn.name, msg.name);
  requireEqual(msgIn.importantNum.isValid(), msg.importantNum.isValid());
  requireEqual(msgIn.importantNum.get().toInt(), msg.importantNum.get().toInt());
  requireEqual(msgIn.timestamps.at(0), msg.timestamps.at(0));
  requireEqual(msgIn.timestamps.at(1), msg.timestamps.at(1));
  requireEqual(msgIn.timestamps.at(2), msg.timestamps.at(2));
  requireEqual(msgIn.timestamps.at(3), msg.timestamps.at(3));
}

}  // End namespace BitOps
