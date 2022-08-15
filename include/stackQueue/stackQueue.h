#pragma once
#define MAX 2000

// 栈定义

//顺序栈
typedef struct {
	int data[MAX];
	int top;
} SqStatck;

//链栈
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode;

// 队定义

//顺序队列
typedef struct {
	int data[MAX];
	int front;
	int rear;
} SqQueue;

//链队列
typedef struct QNode {
	int data;
	struct QNode *next;
} QNode;

typedef struct {
	QNode *front;
	QNode * rear;
} LiQueue;


