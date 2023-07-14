
/**
 * @author: SEKin 
 * @Date: 2023-04-24 16:37:17 
 * @description:  二叉树递归遍历
 * @Last Modified time: 2023-04-24 16:37:17 
 */
#include "../tree.h"
#include <iostream>
using std::cout;
using std::endl;


// 先序遍历
void preVist(BTNode * tree){
	if(!tree){
		return;
	}
	cout << tree->data << " ";
	preVist(tree->lchild);
	preVist(tree->rchild);

}

// 中序遍历
void midVist(BTNode * tree){
	if(!tree){
		return;
	}
	midVist(tree->lchild);
	cout << tree->data << endl;
	midVist(tree->rchild);

}

// 后序遍历
void postVist(BTNode * tree){
	if(!tree){
		return;
	}
	postVist(tree->lchild);
	postVist(tree->rchild);
	cout << tree->data << " ";

}
//层次遍历
void levVist(BTNode * tree){
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
		}
		if(cur->lchild){
			nodeArr[++top] = cur->lchild;
			leg++;
		}
	}
	
}	
