#include "./mystring.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//串的赋值
int StrAssign(Strs &str, char *ch)
{
	if (str.ch)
	{
		free(str.ch);
	}
	// 先获取长度
	int len;
	char *c = ch;
	while (*c)
	{
		c++;
		len++;
	}

	if (len == 0)
	{
		str.length = 0;
		str.ch = NULL;
		return 1;
	}
	else
	{
		str.ch = (char *)malloc((len + 1) * sizeof(char));
		if (str.ch == NULL)
		{ // 当内存不足的情况下分配时，malloc会返回 NULL
			return 0;
		}
		// 再重新循环赋值
		c = ch;
		for (int i = 0; i <= len; i++)
		{
			str.ch[i] = *c;
			c++;
		}
		str.length = len;
		return 1;
	}
}

void init()
{
	int L = 40;
	Strs S;
	S.length = L;
	S.ch = (char *)malloc((L + 1) * sizeof(char));
	cout << S.length << endl;
	free(S.ch);
	char k[] = "asdfafas";
	char *c = "abcd";
	char *a = k;
	Strs b;
	b.ch = (char *)malloc(9 * sizeof(char));
	StrAssign(b, a);
	cout << b.length << " " << b.ch << " " << b.ch[0] <<endl;

	Strs d;
	d.length = 45;
	d.ch =k;
	cout << d.ch << " ch"<<endl;
}
int main()
{
	init();
	return 0;
}
