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

## Unordered Container


| No.  | map                                          | unordered_map                                                    |
| :--- | :------------------------------------------- | :--------------------------------------------------------------- |
| 1.   | map is define in  #include <map> header file | unordered_map is defined in #include <unordered_map> header file |
| 2.   | It is implemented by red-black tree.         | It is implemented using hash table.                              |
| 3.   | It is slow.                                  | It is fast.                                                      |
| 4.   | Time complexity for operations is O(log N)   | Time complexity for operations is O(1)                           |

## Tuples

traditional c++ use **std::pair**, the flaw of std::pair is obvious, only two elements can be saved.

#### Basic Operations
There are three core functions for the use of tuples:

std::make_tuple: construct tuple
std::get: Get the value of a position in the tuple
std::tie: tuple unpacking

#### Runtime Indexing

std::get In addition to using constants to get tuple objects, C++14 adds usage types to get objects in tuples:
std::get<> depends on a compile-time constant, so the following is not legal:

```cpp
std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
std::cout << std::get<std::string>(t) << std::endl;
std::cout << std::get<double>(t) << std::endl; // illegal, runtime error
std::cout << std::get<3>(t) << std::endl;
int index = 1;
std::get<index>(t);
```
to use **std::variant<>** (introduced by C++ 17) to provide type template parameters for variant<> You can have a variant<> to accommodate several types of variables provided 



#### Merge and Iteration

merge two tuples, which can be done with std::tuple_cat:

```cpp

auto new_tuple = std::tuple_cat(get_student(1), std::move(t));

// to get the tuple size
template < typename T>
autp tuple_len(T &tpl){
    return std::tuple_size<T>::value;
}

//this will iterate over the tuple
for(int i = 0; i < tuple_len(new_tuple); ++i)
    std::cout << tuple_index(new_tuple,i) << std::endl;




```


