/**
 * @author: SEKin 
 * @Date: 2022-08-01 15:22:45 
 * @description:  单链表
 * @Last Modified time: 2022-08-01 15:22:45 
 */
#include "./linetable.h"
#include <stdlib.h> //C语言库
//一、 A和B是两个单链表（带表头结点），其中元素递增有序。设计一个算法，将A和B归并成一个按元素值非递减有序的链表C，C由A和B中的结点组成。

// 尾插法和归并法
int merge(LNode *A, LNode *B, LNode *&C){
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *r;
	C = A;
	C->next = NULL;
	free(B);
	r = C;
	while (p!= NULL && q!=NULL)
	{
		if(p->data<q->data){
			r->next = p;
			r = r->next;
			p = p->next;
		} else {
			r->next = q;
			r = r->next;
			q=q->next;
		}
	}
	r->next=NULL;
	if(p->next!=NULL){
		r->next = p;
	}
	if(q->next!=NULL){
		r->next = q;
	}
	return 1;
}
