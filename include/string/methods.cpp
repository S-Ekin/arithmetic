#include "../stackQueue/stackQueue.h"
#include "./mystring.h"
#include <iostream>
using namespace std;

// 1. IO匹配判断，类似括号"()"的匹配
int matchPattern(char s[])
{

	SqStatck arr;
	arr.top = -1;
	int i = 0;
	char item;
	while (item != '\0' | i < 100)
	{
		i++;
		item = *s;
		if (item == 'i')
		{
			arr.top++;
			arr.data[arr.top] = item;
		}
		else if (item == 'o')
		{
			char x = arr.data[arr.top];
			if (x != 'i' || arr.top < 0)
			{
				cout << "匹配失败" << endl;
				return 0;
			}
			arr.top--;
		}
		s++;
	}

	if (arr.top > -1)
	{
		cout << "匹配失败" << endl;
		return 0;
	}
	cout << "匹配成功" << endl;
	return 1;
}

// 2. 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾结点，但不设头指针，请写出相应的入队列和出队列算法。
// 这个题目在考试时，是不用自己写链队类型的，是假设类型已经存在

// 入队
void queueNoFrontPush(QNode *& rear, int x){

	QNode * s = (QNode *)malloc(sizeof(QNode));
	s->next = NULL;
	s->data = x;
	//循环链表 先连接以前节点的后面的
	s->next = rear->next;
	rear->next = s;
	rear = s; // rear指向新队尾
}

// 出队
int queueNoFrontDe(QNode *&rear, int &x){
	//先判断队空
	if(rear->next == NULL){
		return 0;
	}

	QNode *front = rear->next->next; // 注意有头节点
	rear->next->next = front->next;
	x = front->data;

	if(front == rear){ // 出队的是尾指针，也就是原先的队列只有一个元素
		rear = rear->next; // 将尾指针指向头节点
	}

	return 1;
}


// 3.如果允许在循环队列的两端都可以进行插入和删除操作，要求：1）写出循环队列的类型定义。2）分别写出从队尾删除和从队头插入的算法

typedef struct 
{
	int data[MAXSIZE];
	int rear;
	int front;
} CircleQue;


int circleInsertFromFront(CircleQue & que, int x){
	// 判断是否溢出
	// if((que.rear + 1 + MAXSIZE ) % MAXSIZE == que.front){
	if((que.front - 1 + MAXSIZE ) % MAXSIZE == que.rear){
		return 0;
	}
	que.data[que.front] = x;
	que.front = (que.front - 1 + MAXSIZE) % MAXSIZE; // 注意正常的写法 
	// que.data[que.front]= x; 错误，注意队首指针位置中不放数据
	return 1;
}

int circleDeFromRear(CircleQue & que, int &x){
	// 判断是否溢出
	if(que.front == que.rear ){
		return 0;
	}
	x = que.data[que.rear];
	que.rear = (que.rear - 1 + MAXSIZE) % MAXSIZE;
	return 1;
}

