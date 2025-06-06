/**
 * @author: SEKin
 * @Date: 2025-06-04 13:40:05
 * @description:  各种数组容器
 * @Last Modified time: 2025-06-04 13:40:05
 */
#include <array>
#include <iostream>
#include <vector>
using std::array, std::vector;
using std::cout, std::endl;

void test()
{
	int c_arr[5] = {1, 2, 3, 4, 5};			 // 默认的数组类型，继承自c数组，没有边界检查，会自动退化为指针
	array<int, 5> arr = {1, 2, 3, 4, 5}; // 对c数组的封装，有边界检查，不会自动退化为指针

	cout << "c_arr " << c_arr[10] << endl;
	cout << "arr " << arr.at(0) << endl;
}

void test2()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	// lambda
	auto print_V = [&items = arr]
	{
		for (auto item : items)
		{
			cout << item << " ";
		}
		cout << endl;
	};

	print_V();

}

int main()
{
	test2();
}
