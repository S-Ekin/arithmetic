#include <iostream>
#include <string>
#include "../include/arr/ArrOpt.cpp"
#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
	// 打印utf-8的中文格式
	SetConsoleOutputCP(936);
	cout << "打发撒3eeeee4"<< endl;
	ArrOpt arrOpt;
	arrOpt.handle();
	cin.get();
	return 0;
}