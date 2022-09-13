#include "../stackQueue/stackQueue.h"
#include "./mystring.h"
#include <iostream>

using namespace std;

int matchPattern(char s[])
{

	SqStatck arr;
	arr.top = -1;
	int i = 0;
	char item;
	while (item != '\0' | i < 100)
	{
		i++;
		s++;
		item = *s;
		if (item == 'i')
		{
			arr.top++;
			arr.data[arr.top] = item;
		}
		else if (item == 'o')
		{
			char x = arr.data[arr.top];
			if (x != 'i' || arr.top < 0)
			{
				cout << "匹配失败" << endl;
				return 0;
			}
			arr.top--;
		}
	}

	if (arr.top > -1)
	{
		cout << "匹配失败" << endl;
		return 0;
	}
	cout << "匹配成功" << endl;
	return 1;
}
