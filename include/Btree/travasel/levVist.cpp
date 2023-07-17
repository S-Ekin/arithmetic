/**
 * @author: SEKin 
 * @Date: 2023-07-17 16:07:39 
 * @description:  层次遍历 主要用队列实现
 * @Last Modified time: 2023-07-17 16:07:39 
 */
//层次遍历 用队列实现
#include <iostream>
#include "../tree.h"
using std::cout;
using std::endl;

void levVist (BTNode * tree){
	BTNode * sqList[MaxSize] = {};
	int rear=  1;
	int front = 0;
	sqList[rear] = tree;

	while (rear!=front) // 队空
	{
		front = (front + 1) % MaxSize;
		BTNode * p = sqList[front];
		cout << p->data << " ";
		if(p->lchild){
			rear = (rear + 1) % MaxSize;
			if(rear != front){ // 堆满
				sqList[rear] = p->lchild; 
			}
		}
		if(p->rchild){
			rear = (rear + 1) % MaxSize;
			if(rear != front){ // 堆满
				sqList[rear] = p->rchild; 
			}
		}
	}
	
	
}	
