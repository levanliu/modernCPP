#include <array>
#include <forward_list>
#include<iostream>
#include<algorithm>

void foo(int *p,int len)
{
    for(int i=0;i<len;i++){
		std::cout << p[i] << std::endl;
	}
}

int main()
{
	std::array<int, 4> arr = {1,2,3,4};

	foo(arr.data(),arr.size());
	foo(&arr[0],arr.size());
	std::sort(arr.begin(), arr.end());
	// std::forward_list<typename Tp>

	return 0;
}
