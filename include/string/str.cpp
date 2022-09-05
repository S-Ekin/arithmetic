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
		str.ch = NULL;
	}
	// 先获取长度
	int len = 0; // 要是不给初始值0,len会有一个默认值，并且是栈给的一个随机值
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

// 串的比较
int strCompare(Strs s1, Strs s2){

	for (int i = 0; i < s1.length || i < s2.length; i++)
	{
		if(s1.ch[i]!= s2.ch[i]){
			return s1.ch[i] - s2.ch[i];
		}
	}
	return s1.length - s2.length;
}

// 串的连接
int strContact(Strs & str, Strs s1, Strs s2){
	if(str.ch){
		free(str.ch);
	}
	// 申请自己的空间, 注意 + 1
	str.ch = (char *)malloc((s1.length + s2.length + 1)*sizeof(char));
	// 判断是否申请成功
	if(!str.ch){
		return 0;
	}
	// 开始一个个复制
	int i  = 0;
	while (i< s1.length)
	{
		str.ch[i] = s1.ch[i];
		i++;
	}
	int j  = 0;
	while (j< s2.length)
	{
		str.ch[i + j] = s2.ch[j];
		j++;
	}

	str.length = i + j;
	return 1; 
}

// 串的子串
// pos：子串开始的位置
int subStr(Strs & sub, Strs s, int pos, int leg){
	//先判断	参数的合法性
	if(pos <0 || leg < 0 || (pos + leg) > s.length || pos >= s.length){
		return 0;
	}

	if(sub.ch){
		free(sub.ch);
		sub.ch = NULL;
	}

	if(leg == 0){
		sub.ch = NULL;
		sub.length = 0;
		return 1;
	}

	int j =0;
	sub.ch = (char *)malloc(sizeof(char) * (leg + 1));
	while (j < leg)
	{
		sub.ch[j] = s.ch[pos + j];
		j++;
	}
	sub.ch[leg] = '\0';
	sub.length = leg;
	return 1;
	
}

// 清空串

int clarnStr(Strs &s){
	if(s.ch){
		free(s.ch);
		s.ch = NULL;
	}
	s.length = 0;
	return 1;
}

