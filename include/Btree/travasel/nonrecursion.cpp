/**
 * @author: SEKin 
 * @Date: 2023-04-24 16:37:17 
 * @description:  二叉树非递归遍历  栈实现
 * 递归与非递归之间的转化，重要的几点
 * 必须使用【栈】来模拟
 * 栈保存的对象就算递归函数的参数。注意多个参数的情况
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

	while ( top > -1)
	{
		BTNode *cur = nodeArr[top--];
		cout << cur->data << " ";
		if(cur->rchild){
			nodeArr[++top] = cur->rchild;
		} 
		
		if(cur->lchild){
			nodeArr[++top] = cur->lchild;
		}
	}
}	

// 非递归后序遍历 逆后序是 前序里 左右树顺序反过来
void noneRePostVist(BTNode * tree){
	int top = 0;
	BTNode * nodeArr[MaxSize] = {tree};

	int top1 = 0;
	int res[MaxSize] = {};

	while (top > -1)
	{
		BTNode *cur = nodeArr[top--];
		res[top1++] = cur->data;

		// 注意这里与前序相反
		if(cur->lchild){
			nodeArr[++top] = cur->lchild;
		}
		if(cur->rchild){
			nodeArr[++top] = cur->rchild;
		}
	}

	while (top1)
	{
		cout << res[--top1] << " " ;
	}
	
}	


// 中序遍历
void noneReMidVist(BTNode * tree){
	BTNode * nodeArr[MaxSize] = {};
	int top = -1;

	BTNode *cur = tree;
	while (top > -1 || cur)
	{
		while (cur) //添加左子树
		{
			nodeArr[++top] = cur;
			cur = cur->lchild;
		}

		if(top > -1){//消费栈里的内容，并转换方向到右子树
			cur = nodeArr[top--];
			cout << cur->data << " ";
			cur = cur->rchild; //避免了再次轮回时，又添加左子树
		}

	}

}	

