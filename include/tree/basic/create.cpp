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
void createBT(BTNode *& tree){
	int str;
	cin >> str;
	if(str != 0) {
		tree =(BTNode *)malloc(sizeof(BTNode));
		tree->data = str;
		cout << str <<" 左子树：" << endl;
		createBT(tree->lchild);
		cout << str <<" 右子树：" << endl;
		createBT(tree->rchild);
	} else {
		tree = nullptr;
	}
}
