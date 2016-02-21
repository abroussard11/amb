/**
 * amb/Attribute.h
 */

#ifndef AMB_ATTRIBUTE_H_
#define AMB_ATTRIBUTE_H_

namespace amb {

template <class T>
struct Attribute {
  using value_type = T;
  using Func = void (*)(void*, const T&);

  void* _owner;
  Func _func;
  T data;

  Attribute()
      : _owner(0),  //
        _func(0),   //
        data() {
    // Empty
  }

  Attribute(void* owner, Func func)
      : _owner(owner),  //
        _func(func),    //
        data() {
    // Empty
  }

  operator const T&() const {
    std::cout <<
      "Attribute::operator T()"
      << std::endl;
    std::cout <<
      "data.x = " << data.x
      << std::endl;
    return data;
  }

  void operator=(const T& t) { _func(_owner, t); }

  void set(const T& t) { data = t; }
};

}  // End namespace amb

#if 0
// Copy/Paste from unit tests
namespace test {

struct MyType {
  int x;
  int y;
};

template <typename T>
void assign(void* obj, const MyType& mytype) {
   static_cast<T*>(obj)->setMyType(mytype);
};

class MyModel {
  public:
  amb::Attribute<MyType> data;

  MyModel() : data(this, &assign<MyModel>) {
    // Empty
  }

  void setMyType(const MyType& mytype) {
    data.set(mytype);
  }
};

void AmbUnitTest::testAttribute() {
  MyModel model;
  MyType _amb = {3, 5};

  model.data = _amb;
  requireEqual(static_cast<MyType>(model.data).x, 3);
  requireEqual(static_cast<MyType>(model.data).y, 5);

  MyType _amb2;
  _amb2 = model.data;
  requireEqual(_amb2.x, 3);
  requireEqual(_amb2.y, 5);
}

} // End tests
#endif  // 0

#endif  // AMB_APP_H_
