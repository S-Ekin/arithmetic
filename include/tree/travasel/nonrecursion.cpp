/**
 * @author: SEKin 
 * @Date: 2023-04-24 16:37:17 
 * @description:  二叉树非递归遍历
 * @Last Modified time: 2023-04-24 16:37:17 
 */
#include <iostream>
#include "../tree.h"
using std::cout;
using std::endl;


// 非递归前序遍历
void noneRePretVist(BTNode * tree){
	int top = 0;
	BTNode * nodeArr[MaxSize] = {tree};
	int leg = 1;

	while (leg && top > -1)
	{
		leg--;
		BTNode *cur = nodeArr[top--];
		cout << cur->data << " ";
		if(cur->rchild){
			nodeArr[++top] = cur->rchild;
			leg++;
		} else if(cur->lchild){
			nodeArr[++top] = cur->lchild;
			leg++;
		}
	}
}	

// 非递归后序遍历
void noneRePostVist(BTNode * tree){
	int top = 0;
	BTNode * nodeArr[MaxSize] = {tree};
	int leg = 1;

	int top1 = 0;
	int leg1 = 0;
	int res[] = {};

	while (leg && top > -1)
	{
		leg--;
		BTNode *cur = nodeArr[top];
		res[top] = cur->data;
		if(cur->rchild){
			nodeArr[++top] = cur->rchild;
			leg++;
		}else if(cur->lchild){
			nodeArr[++top] = cur->lchild;
			leg++;
		}
	}
}	
