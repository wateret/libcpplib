//
// Check the order of construction/destruction for object members
//
// Turns out
// - construction in normal order
// - destruction in reverse order
//
// Releated URL
// - https://stackoverflow.com/questions/2254263/order-of-member-constructor-and-destructor-calls

#include <iostream>

class A {
 public:
  A()  { std::cout << "A()" << std::endl; }
  ~A() { std::cout << "~A()" << std::endl; }
};

class B {
 public:
  B()  { std::cout << "B()" << std::endl; }
  ~B() { std::cout << "~B()" << std::endl; }
};

class Container {
 public:
  Container()  { std::cout << "Container()" << std::endl; }
  ~Container() { std::cout << "~Container()" << std::endl; }
  A a;
  B b;
};

int main() {
  Container c;
  return 0;
}
