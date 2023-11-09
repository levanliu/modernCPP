#include <iostream>
#include <memory>

class A;
class B;

class A {
 public:
  std::shared_ptr<B> pointer;
  ~A() { std::cout << "A was destroyed" << std::endl; }
};
class B {
 public:
  std::shared_ptr<A> pointer;
  ~B() { std::cout << "B was destroyed" << std::endl; }
};
int main() {
  std::shared_ptr<A> a = std::make_shared<A>();
  std::shared_ptr<B> b = std::make_shared<B>();
  a->pointer = b;
  b->pointer = a;

  return 0;
}

/*
 * std::weak_ptr has no implemented * and -> operators, therefore it cannot
 * operate on resources. std::weak_ptr allows us to check if a std::shared_ptr
 * exists or not. The expired() method of a std::weak_ptr returns false when the
 * resource is not released; Otherwise, it returns true. Furthermore, it can
 * also be used for the purpose of obtaining std::shared_ptr, which points to
 * the original object. The lock() method returns a std::shared_ptr to the
 * original object when the resource is not released, or nullptr otherwise
 * */
