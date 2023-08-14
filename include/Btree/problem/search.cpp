/**
 * @author: SEKin
 * @Date: 2023-07-19 16:17:32
 * @description:  各种问题
 * @Last Modified time: 2023-07-19 16:17:32
 */
#include "../tree.h"

// 求二叉链表的高度 //利用俩个队列相互存下一级的节点
int getBTHeight(BTNode *tree)
{

	BTNode *sqList1[MaxSize] = {};
	int front1, rear1 = 0;

	BTNode *sqList2[MaxSize] = {};
	int front2, rear2 = 0;

	BTNode *p = tree;
	sqList1[++rear1] = p;
	int lev = 0;
	while (front1 != rear1 || front2 != rear2)
	{
		if (front1 != rear1)
		{
			front1 = (front1 + 1) % MaxSize;
      if(front1 == rear1){
        lev++;
      }
      p = sqList1[front1];
			if (p->lchild)
			{
				rear2 = (rear2 + 1) % MaxSize;
				sqList2[rear2] = p->lchild;
			}

			if (p->rchild)
			{
				rear2 = (rear2 + 1) % MaxSize;
				sqList2[rear2] = p->rchild;
			}
		}
		else
		{
      front2 = (front2 + 1) % MaxSize; 
      if(front2 == rear2){
        lev++;
      }
      p = sqList2[front2];
			if (p->lchild)
			{
				rear1 = (rear1 + 1) % MaxSize;
				sqList1[rear1] = p->lchild;
			}

			if (p->rchild)
			{
				rear1 = (rear1 + 1) % MaxSize;
				sqList1[rear1] = p->rchild;
			}
		}
	}

  return lev;
}

// 判定是否是完全二叉树 找到最后一个节点的索引及其高度
bool isCompeleteBT(BTNode *tree){
	int rear = 0 , front = 0;
	BTNode *sqList[MaxSize] = {};
	BTNode *treeArr[20] ={};
	int leg = 0;

	front = (front + 1)%MaxSize;
	sqList[front] = tree;
	treeArr[leg] = tree;

	while (front!=rear)
	{
		rear = (rear + 1)%MaxSize;
		BTNode * p = sqList[rear];
		if(p->lchild){
			front = (front + 1)%MaxSize;
			sqList[front] = p->lchild;
			leg++;
			treeArr[leg] = p->lchild;
		}
		
		if(p->rchild){
			front = (front + 1)%MaxSize;
			sqList[front] = p->rchild;
			leg++;
			treeArr[leg] = p->rchild;
		}
	}

	int last = leg + 1;
	int par = last / 2 - 1;

	if(treeArr[par]->rchild == treeArr[leg] && last % 2 != 0){
		return true;
	}else if(last % 2 ==0 && treeArr[par]->lchild == treeArr[leg] ){
		return true;
	}else{
		return false;
	}
}

