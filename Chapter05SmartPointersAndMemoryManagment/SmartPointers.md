#### RAII and Reference Counting


first important concept : reference counting.
The reference count is counted to prevent memory leaks

#include <memory>
std::shared_ptr
std::unique_ptr
std::weak_ptr


- 5.2  std::shard_ptr

std::shared_ptr is a smart pointer that records how many shared_ptr points to an object, eliminating to call delete,
which automatically deletes the object when the reference count becomes zero.

use std::make_shared to eliminate the explicit to use of new.
std::make_shared will allocate the objects in the generated parameters.


```cpp

#include<iostream>
#include<memory>
void foo(std::shared_ptr<int> i){
 (*i) ++;
}

int main()
{
    //auto pointer = new int(10); //illegal, no direct assignment
    //Construct a std::shared_ptr

    auto pointer = std::make_shared<int> (10);
    foo(pointer);
    std::cout << *pointer << std::endl; // 11
    return 0;
}

```

std::shared_pt can get pointer through the get() method and reduce the reference count by reset(). And see the 
reference count of an object by **use_count()**.

```cpp
auto pointer = std::make_shared<int>(10);
auto pointer2 = pointer; // reference count + 1
auto pointer3 = pointer; // reference count + 1
int *p = pointer.get(); // no increase of reference count

std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::end; //3
std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; //3

pointer2.reset();
std::count << "reset pointer2:" << std::endl;




std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2

std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; //pointer2 has reset 0

std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; //2

pointer3.reset();
std::cout << "reset pointer3:" << std::endl;


std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1

std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; //pointer2 has reset 0

std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; //pointer3 has reset 0

```


