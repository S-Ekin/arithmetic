/**
 * @author: SEKin 
 * @Date: 2024-07-27 10:06:06 
 * @description:  树型查找
 * @Last Modified time: 2024-07-27 10:06:06 
 */

#include "../Btree/tree.h"
#include "stdlib.h"

// 二叉排序树
BTNode * BSTSearch(BTNode *bt, int key){

	if(bt == nullptr){
		return nullptr; // 查找不成功
	} else {
		if(bt->data == key){
			return bt;
		} else if (key < bt->data){
			return  BSTSearch(bt->lchild, key);
		} else {
			return BSTSearch(bt->rchild, key);
		}
	}
}


// 二叉排序树插入
int BSTInsert(BTNode*& bt, int key){
	if(bt == nullptr){
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->lchild=bt->rchild=nullptr;
		bt->data = key;
		return 1; 
	} else {
		if(bt->data == key){
			return 0;
		} else if (key < bt->data){
			return  BSTInsert(bt->lchild, key);
		} else {
			return BSTInsert(bt->rchild, key);
		}
	}
}

// 二叉排序树构造
void CreateBST(BTNode *& bt, int key[], int n){
	int i;
	bt = NULL;
	for (size_t i = 0; i < n; i++) {
		BSTInsert(bt, key[i]);
	}
}
