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
	int arr[arrleg] = {1,0,3,4,0,6,7,8,9,10,0,12,0,0,15,0,17};
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
