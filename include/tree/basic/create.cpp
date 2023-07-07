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

// 二叉树得构建
void createBT(BTNode *& tree){

	char str;
	cin >> str;
	BTNode *p =(BTNode *)malloc(sizeof(BTNode));
	// BTNode *p = new BTNode;

	if(str == '#'){
		p = nullptr;
	}else {
		p->data = str;
		createBT(p->lchild);
		createBT(p->rchild);
	}
}

void test(){
	cout << "er" << endl;
}
