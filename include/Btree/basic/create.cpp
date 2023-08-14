/**
 * @author: SEKin 
 * @Date: 2023-07-04 14:38:46 
 * @description:  二叉树得构建
 * @Last Modified time: 2023-07-04 14:38:46 
 */

#include "./util.h"
#include "../tree.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// 利用前序遍历构建二叉树得
void createBTByCin(BTNode *& tree){
	int str;
	cin >> str;
	if(str != 0) {
		tree =(BTNode *)malloc(sizeof(BTNode));
		tree->data = str;
		cout << str <<" 左子树：" << endl;
		createBTByCin(tree->lchild);
		cout << str <<" 右子树：" << endl;
		createBTByCin(tree->rchild);
	} else {
		tree = nullptr;
	}
}

// 通过数组建立完全二叉树
void createBTByArr(BTNode *& tree){
	int arrleg = 17;
	int arr[arrleg] = {1,2,3,4,0,6,7,8,9,0,11};
	BTNode * nodeArr[arrleg] = {};
	nodeArr[0] = tree;

	for (int i = 0; i < arrleg; i++)
	{
		BTNode *par = nodeArr[i];
		if (!par)
		{
			continue;
		}
		
		par->data = arr[i];
		
		int lcVal = 2*(i+1);
		if(lcVal > arrleg){
			break;
		} else {
			int val = arr[lcVal - 1];
			if(val){
				BTNode * lp = new BTNode;
				// BTNode * lp = nodeArr[lcVal - 1]; 报错 空指针
				lp->data = val;
				par->lchild = lp;
				nodeArr[lcVal - 1] = lp;
			}else {
				// par->lchild = nullptr;
			}
			
		}

		int rcVal = lcVal + 1;
		if(rcVal > arrleg){
			break;
		} else {
			int val = arr[rcVal - 1];
			if(val){
				BTNode * rp = new BTNode;
				rp->data = val;
				par->rchild = rp;
				nodeArr[rcVal - 1] = rp;
			} else {
				// par->rchild = nullptr;
			}
			
		}
	}

}


void mapTree(int start, int end, int midArr[], int preArr[], int preParIndex, BTNode *& parNode) {
		if(end - start < 1){
			return;
		}

		int leftChildNum = 0, midParIndex = -1;
		int parVal = preArr[preParIndex];

		// 中序里找到父节点
		for (size_t i = start; i <= end; i++)
		{
			int item = midArr[i];
			if(item == parVal){
				midParIndex = i;
				break;
			} else {
				leftChildNum++;
			}
		}

		if(midParIndex - start > 0){ // 存在左子树
			BTNode * left = new BTNode();
			int leftIndex = preParIndex + 1;
			left->data=preArr[leftIndex];
			parNode->lchild = left;
			mapTree(start, midParIndex - 1, midArr, preArr, leftIndex, left);
		}

		if(end - midParIndex > 0){// 存在右子树
			BTNode * right = new BTNode();
			int rightIndex = preParIndex + 1 + leftChildNum;
			right->data=preArr[rightIndex];
			parNode->rchild = right;
			mapTree(midParIndex + 1, end, midArr, preArr, rightIndex, right);
		}
	}

// 根据 前序和中序数组 递归构造二叉树
void createBTByTravasel(BTNode *& tree){
  	int leg = 8;
	int preArr[leg] = {1,2,4,9,5,3,7,14};
	cout << "原前序：1 2 4 9 5 3 7 14" <<endl;
	int midArr[leg] = {4,9,2,5,1,3,14,7};
	cout << "原中序：4 9 2 5 1 3 14 7" <<endl;

	tree->data = preArr[0];
	mapTree(0, leg - 1, midArr, preArr, 0, tree);
}

// 根据 前序和中序数组 非递归构造二叉树
void nonReCreateBTByTravasel(BTNode *& tree){
  	int leg = 8;
	int preArr[leg] = {1,2,4,9,5,3,7,14};
	cout << "1 2 4 9 5 3 7 14" <<endl;
	int midArr[leg] = {4,9,2,5,1,3,14,7};
	tree->data = preArr[0];

	int top = -1;
	int stackList[MaxSize][3]= {};
	BTNode *stackBTList[MaxSize]= {};
	++top;
	stackList[top][0] = 0;
	stackList[top][1] = leg - 1;
	stackList[top][2] = 0;
	stackBTList[top] = tree;

	while (top > -1)
	{
		int *indexArrs = stackList[top];
		int start = indexArrs[0];
		int end = indexArrs[1];
		int preParIndex = indexArrs[2];
		BTNode * parNode = stackBTList[top];
		top--;

		int parVal = preArr[preParIndex];
		int leftChildNum =0;
    	int midParIndex = 0;
		for (size_t i = start; i <= end; i++)
		{
			int item = midArr[i];
			if(item == parVal){
				midParIndex = i;
				break;
			} else {
				leftChildNum++;
			}
		}
		
		if(end - midParIndex > 0){// 存在右子树
			BTNode * right = new BTNode();
			int rightIndex = preParIndex + 1 + leftChildNum;
			right->data=preArr[rightIndex];
			parNode->rchild = right;
			
			top++;
			stackList[top][0] = midParIndex + 1;
			stackList[top][1] = end;
			stackList[top][2] = rightIndex;
			stackBTList[top] = right;
		}

		if(midParIndex - start > 0){ // 存在左子树
			BTNode * left = new BTNode();
			int leftIndex = preParIndex + 1;
			left->data=preArr[leftIndex];
			parNode->lchild = left;
			top++;
			stackList[top][0] = start;
			stackList[top][1] = midParIndex - 1;
			stackList[top][2] = leftIndex;
			stackBTList[top] = left;
		}
	}
}
