/**
 * @author: SEKin 
 * @Date: 2022-08-15 15:37:08 
 * @description:  
 * @Last Modified time: 2022-08-15 15:37:08 
 */

#include <stdlib.h>
#include "./stackQueue.h"

// 顺序队
void intQueue(SqQueue & qu){
	qu.front = qu.rear = 0;
}

int isQueueEmpty(SqQueue qu){
	if(qu.front = qu.rear){
		return 1;
	} else {
		return 0;
	}
}

int enQueue(SqQueue &qu, int x){
	if((qu.rear + 1)% MAX == qu.front){ // 判断是否溢出
		return 0;
	}
	qu.rear = (qu.rear + 1 )%MAX;
	qu.data[qu.rear] = x;
	return 1;
}

int deQueue(SqQueue &qu, int & x){
	if(isQueueEmpty(qu)){
		return 0;
	}
	qu.front = (qu.front + 1) % MAX;
	x = qu.data[qu.front]; // 此时front 所指的位置是头指针，虽然有数据，但是属于队列了
}


// 链队
void intQueue(LiQueue *& lqu){
	lqu = (LiQueue *)malloc(sizeof(LiQueue));
	lqu->front = lqu->rear = NULL;
}

int isQueueEmpty(LiQueue *lqu){
	if(lqu->front == NULL || lqu->rear == NULL){
		return 1;
	} else {
		return 0;
	}
}
// 入队
int enQueue(LiQueue *lqu, int x){
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->next =NULL;
	p->data = x;
	if(isQueueEmpty(lqu)){
		lqu->rear = p;
		lqu->front = p;
	} else {
		lqu->rear->next = p;  //关键
		lqu->rear = p;
	}
}

// 出队
int deQueue(LiQueue *lqu, int & x){
	QNode *p;

	if(isQueueEmpty(lqu)){
		return 0;
	} else {
		p = lqu->front;
	}

	if(lqu->rear == lqu->front){ // 只有一个节点
		lqu->front = lqu->rear = NULL;
	} else {
		lqu->front =lqu->front->next;
	}
	x = p->data;
	free(p);
	return 1;
}

