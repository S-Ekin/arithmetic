/**
 * @author: SEKin
 * @Date: 2022-09-05 20:22:07
 * @description:
 * @Last Modified time: 2022-09-05 20:22:07
 */
#include "./mystring.h"
#include "./str.cpp"
#include <iostream>
#include "./methods.cpp"
using namespace std;

int i1;
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
	cout << b.length << " " << b.ch << " " << b.ch[0] << endl;

	Strs d;
	d.length = 45;
	d.ch = k;
	cout << d.ch << " ch" << endl;
}

void strContactT()
{

	Strs s;
	Strs s2;
	Strs s1;
	// 要是不给NULL,栈会默认给s.ch = "";导致 StrAssign 里的 free(str.ch)报错
	s.ch = NULL;
	s1.ch = NULL;
	s2.ch = NULL;
	StrAssign(s1, "123456");
	StrAssign(s2, "abcdef");
	int res = strContact(s, s1, s2);
	cout << (res ? s.ch : "错误") << endl;

	subStr(s, s2,3,2);
	cout << s.ch << endl;

}
int main()
{
	char s[] = {'i','i','o','i','o','i', 'o','o','\0'};

	matchPattern(s);
	// strContactT();
	return 0;
}
