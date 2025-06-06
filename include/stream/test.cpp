/**
 * @author: SEKin
 * @Date: 2025-06-03 09:02:59
 * @description: 从输入流中解析出数字
 * @Last Modified time: 2025-06-03 09:02:59
 */
#include <iostream>
#include <sstream>
using std::cout, std::endl;
using std::istringstream;

int main()
{
	const char buff[] = "x20";
	int v = 0;
	std::string  text;
	{
		istringstream is(buff);
		is >> std::hex >> v >> text;
		std::cout << "数字:" << v << std::endl;
		std::cout << "剩余的字符串:" << text << std::endl;
		if (is.fail())
			std::cout << "发生错误" << std::endl;
		cout << buff << "---------------------" << v << endl;
	}
}
