/**
 * @author: SEKin 
 * @Date: 2022-07-29 17:16:42 
 * @description:  顺序表
 * @Last Modified time: 2022-07-29 17:16:42 
 */
#include "./linetable.h"
#include <iostream>

// 从小到大排列的顺序表
int findElem(sqList arr, int x){
	int i;
	for ( i = 0; i < arr.length; i++)
	{
		if(x< arr.data[i]){
			return i;
		}
	}
	return -1;
}

// 顺序表的插入
int insert(sqList & arr, int x, int p){
	if(p<0 || p > arr.length || p == MAXA){
		return 0;
	}
	int a,b;
	//在最后面加一个空格
	for (int i = arr.length-1; i > p; i--)
	{
		arr.data[i+1] = arr.data[i];
	}
	// 要插入的位置以及腾出位置了
	arr.data[p] = x;
	arr.length++;
	return 1;
}

//顺序表的删除
int delElem(sqList &arr, int x, int p, int & e){
	if(p<0 || p > arr.length - 1 || p == MAXA){ // 注意是 arr.length - 1
		return 0;
	}
	e = arr.data[p];
	int i;
	for ( i = p; i < arr.length -1; i++)
	{
		arr.data[i] = arr.data[i+1];
	}
	arr.length--;
	// 不用想着是不是还要删掉最后一个元素，因为数组是固定大小的，添加和删除在物理上是没有减少和增加内存空间的。
}

// 初始化
void initList(sqList &l){
	l.length = 0;
}

// 获取元素
int getElem(sqList l, int p, int &e){
	if(p<0 || p > l.length -1 || p == MAXA){
		return 0;
	}
	e = l.data[p];
	return 1;
}
