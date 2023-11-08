## Linear Container
**std::array**
- 1. Once the size of the **std::array** object is fixed. use **std::array**.
- 2. **std::vector** is automatically expanded, when a large amount of data is stored, and the container is deleted, the container does not automatically return the corresponding memory of the deleted element.<< in this case, need **shrink_to_fit()** to release this part of the memory>>
```cpp
std::vector<int> v;
std::cout << "size:" << v.size() << std::endl;
std::cout << "capacity:" <<
v.capacity() << std::endl;
v.push_back(1);
v.push_back(2);
v.push_back(3);
std::cout << "size:" << v.size() << std::endl; //output 3
std::cout << "capacity:" << v.capacity() << std::endl; //output 4

v.push_back(4);
v.push_back(5);
std::cout << "size:" << v.size() << std::endl;
std::cout << "capacity:" << v.capacity() << std::endl;
v.clear();
std::cout << "size:" << v.size() << std::endl;
std::cout << "capacity" << v.capacity() << std::endl;

```

