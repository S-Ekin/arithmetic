/**
 * @author: SEKin 
 * @Date: 2022-08-01 15:22:45 
 * @description:  单链表
 * @Last Modified time: 2022-08-01 15:22:45 
 */
#include "./linetable.h"
#include <stdlib.h> //C语言库
//一、 A和B是两个单链表（带表头结点），其中元素递增有序。设计一个算法，将A和B归并成一个按元素值非递减有序的链表C，C由A和B中的结点组成。

//归并法
int merge(LNode *A, LNode *B, LNode *&C){
	LNode *p = A->next;  //来跟踪A的最小值结点。
	LNode *q = B->next;	 //来跟踪B的最小值结点
	LNode *r; 			 //始终指向c的终端结点
	C = A;
	C->next = NULL;
	free(B);
	r = C;    			//刚开始，r指向c，因为此时头结点也是终端结点
	// 尾插法思想
	while (p!= NULL && q!=NULL)
	{
		if(p->data<=q->data){
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
	// 连接剩余节点
	if(p->next!=NULL){
		r->next = p;
	}
	if(q->next!=NULL){
		r->next = q;
	}
	return 1;
}

// 尾插法建立链表, 最终创建的顺序与 arr 顺序相同
void createListR(LNode *&C, int arr[], int n){
	LNode *s, *r; 							//s指向新指针节点， r始终指向尾节点指针
	C = (LNode *) malloc(sizeof(LNode)); 	//创建头节点
	C->next = NULL;
	r = C; 									//初始化为节点;
	int i;	
	// 进行尾插
	for ( i = 0; i < n; i++)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = arr[i];
		// s->next = NULL; 					 这个有点多余
		r->next=s;
		r=r->next;
	}
	r->next=NULL;
}

// 头插法, 最终创建的顺序与 arr 顺序相反
void createListF(LNode *&C, int arr[], int n){
	LNode * s;
	C = (LNode *) malloc(sizeof(LNode)); 	
	C->next = NULL;
	// 注意不需要跟踪尾节点了
	int i;
	for ( i = 0; i < n; i++)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data=arr[i];
		// 关键点, 
		s->next = C->next;			//新的节点后面链接之前的开始节点
		C->next=s; 					//让头指针总是指向新的节点
	}
}

int findAndDelete(LNode *C, int x){
	//先查找
	LNode *p;
	p = C;

	while (p->next!=NULL) 			//之所以要使 p 指向所要动除结点的前驱结点，而不是直接指向所要删除结点本身，是因为要删除一个结点必须知道其前驱结点的位置
	{
		if(p->next->data==x){  		//此时指针还是在当前的p上，只不过是在操作p的下个链接点
			break;
		}
		p = p->next;
	}

	if(p->next==NULL){
		return 0;
	} else {
		LNode *q;
		q = p->next;
		p->next = q->next; // p->next=p->next->next;
		free(q);
		return 1;
	}
}
