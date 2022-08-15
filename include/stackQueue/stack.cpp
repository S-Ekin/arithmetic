
/**
 * @author: SEKin 
 * @Date: 2022-08-15 14:59:18 
 * @description:  顺序栈和链栈
 * @Last Modified time: 2022-08-15 14:59:18 
 */

#include <stdlib.h>
#include "./stackQueue.h"

// 顺序栈 不用单独构造类型，直接用数组和一个数字指针, 在用到的地方直接写这两句

void initStack (SqStatck &st){
	st.top= -1;
}

int isEmpty(SqStatck st){
	if(st.top == -1){
		return 1;
	} else {
		return 0;
	}
}

int push(SqStatck &st, int x){
	if(st.top ==  MAX - 1){
		return 1;
	} else {
		st.top++;
		st.data[st.top] = x;
		return 0;
	}
}

int pop(SqStatck &st, int &x){
	if(isEmpty(st)){
		return 1;
	}else{
		x = st.data[st.top];
		st.top--;
		return 0;
	}
}


// 链栈
void initStack(LNode *&lst){
	lst = (LNode *)malloc(sizeof (LNode));
	lst->next = NULL;
}
int isEmpty(LNode *st){
	if(st->next == NULL){
		return 1;
	} else {
		return 0;
	}
}

int push(LNode *lst, int &x){
	LNode *p = (LNode *)malloc(sizeof(LNode));
		p->next=NULL;
		p->data = x;
		p->next = lst->next;
		lst->next = p;
}

int pop(LNode *lst, int &x){
	if(isEmpty(lst)){
		return 1;
	}else{
		LNode *p = lst->next;
		x = p->data;
		lst->next = p->next;
		free(p);
		return 1;
	}
}
