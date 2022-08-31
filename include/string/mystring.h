#pragma once
#define MAXSIZE 80

//定长的存储结构
typedef struct 
{
	char str[MAXSIZE+1];  //多出一个\0作为结束标记，它是占位置的
	int length;
} Str;

//变长的存储结构
typedef struct {
	char * ch;
	int length; 
} Strs;
