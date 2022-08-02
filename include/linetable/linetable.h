// #ifndef MaxSize
#pragma once

#define MAXA 50

// 顺序表
typedef struct {
	int data[MAXA];
	int length;
} sqList;

// 单链表
typedef struct LNode {
	int data;
	struct LNode *next;
} LNode;

// 双链表
typedef struct DLNode {
	int data;
	struct DLNode *prior;
	struct DLNode *next;
} DLNode;



// #endif //MAxSize;
