/**
 * @author: SEKin 
 * @Date: 2022-08-02 15:57:30 
 * @description:  双链表
 * @Last Modified time: 2022-08-02 15:57:30 
 */
#include <stdlib.h>
#include "./linetable.h"
#include <iostream>
using namespace std;

//尾插法创建
void createDlistR(DLNode *&C, int arr[], int n){
	DLNode *s, *r;
	C = (DLNode *)malloc(sizeof(DLNode));
	C->next = NULL;
	C->prior= NULL;
	r = C;
	// 开始插入
	for (int i = 0; i < n; i++)
	{
		s = (DLNode *)malloc(sizeof(DLNode));
		s->data = arr[i];
		// 关键处
		s->prior=r;
		r->next =s;
		r=s;
	}
	r->next = NULL;
}

//查找节点
DLNode * findNode(DLNode *C, int x){
	DLNode *p;
	p = C->next;
	while (p!= NULL)
	{
		if(p->data==x){
			break;
		}
		p = p->next;
	}

	// 一下的操作多余了，可以直接利用上面的循环，在找不到时，p会成为尾节点的next,也就是NULL
	// if(p->next==NULL){
	// 	return NULL;
	// }
	// return p->next;
	
	return p;
}
