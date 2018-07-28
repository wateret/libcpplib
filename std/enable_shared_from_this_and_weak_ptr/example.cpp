//
// How/When to use enable_shared_from_this
//
// NOTE
// Looks like the best answer at the URL is wrong in terms of weak_ptr usage.
// weak_ptr pointer should be B::parent, not A::children. Otherwise all the object are removed right after calling CreateA().
// It probably is a mistake.
//
// Related URL
// - https://stackoverflow.com/questions/11711034/stdshared-ptr-of-this

#include <list>
#include <memory>
#include <iostream>

class A;
class B;

class A : public std::enable_shared_from_this<A>
{
 public:
  A() { std::cout << "A()" << std::endl; }
  ~A() { std::cout << "~A()" << std::endl; }
  void addChild(std::shared_ptr<B> child);

 private:
  // note weak_ptr
#ifdef WEAK_CHILDREN
  std::list<std::weak_ptr<B>> children;
#else
  std::list<std::shared_ptr<B>> children;
#endif
};

class B
{
 public:
  B() { std::cout << "B()" << std::endl; }
  ~B() { std::cout << "~B()" << std::endl; }
  void setParent(std::shared_ptr<A> parent);

 private:
#ifdef WEAK_CHILDREN
  std::shared_ptr<A> parent;
#else
  std::weak_ptr<A> parent;
#endif
};

void A::addChild(std::shared_ptr<B> child) {
  children.push_back(child);

  // like this
  child->setParent(shared_from_this());  // ok
  //               ^^^^^^^^^^^^^^^^^^
}

void B::setParent(std::shared_ptr<A> parent) {
  this->parent = parent;
}

std::shared_ptr<A> CreateA() {
  std::shared_ptr<B> child1 = std::make_shared<B>();
  std::shared_ptr<B> child2 = std::make_shared<B>();

  std::shared_ptr<A> parent = std::make_shared<A>();
  parent->addChild(child1);
  parent->addChild(child2);
  return parent;
}

int main() {
  std::shared_ptr<A> p = CreateA();
  std::cout << "End of main" << std::endl;
  return 0;
}
