#include <iostream>
#include <string>
#include "../include/linetable/doubleLink.cpp"
#include <windows.h>
using namespace std;


int main(int argc, char *argv[])
{
	// 打印utf-8的中文格式
	SetConsoleOutputCP(65001);
	int x;
	cin >> x;
	int arr[] = {1,2,3,4,5,6};
	DLNode *C;
	createDlistR(C, arr, 6);
	DLNode *res = findNode(C, x);
	if(res){
		cout << res->data <<endl;
	} else {
		cout << "找不到！" <<endl;
	}
	return 0; 
}
