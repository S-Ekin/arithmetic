#include <iostream>
#include <string>
#include "../include/arr/ArrOpt.cpp"
#include "../include/first/basic.cpp"
#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
	// 打印utf-8的中文格式
	SetConsoleOutputCP(65001);
	ArrOpt arrOpt;
	arrOpt.handle();
	cin.get();
	test();
	return 0;
}
