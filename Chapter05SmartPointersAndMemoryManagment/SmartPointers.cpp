#include <iostream>
#include <memory>
struct Foo {
  Foo() { std::cout << "Foo::Foo" << std::endl; }
  ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
  void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) { std::cout << "f(const Foo&)" << std::endl; }

int main() {
  std::unique_ptr<Foo> p1(std::make_unique<Foo>());

  // p1 is not empty, prints
  if (p1) p1->foo();
  {
    std::unique_ptr<Foo> p2(std::move(p1));
    f(*p2);

    if (p2) p2->foo();
    if (p1) p1->foo();

    p1 = std::move(p2);

    if (p2) p2->foo();
    std::cout << "p2 was detroyed" << std::endl;
  }
  if (p1) p1->foo();

  // Foo instance will be detroyed when leaving the scope
}
