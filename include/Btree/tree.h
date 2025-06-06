/**
 * @author: SEKin 
 * @Date: 2023-04-24 16:57:33 
 * @description:  树形结构定义
 * @Last Modified time: 2023-04-24 16:57:33 
 */

#pragma once
#define MaxSize 100

// 二叉树结点定义
typedef struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
	// 赋值初始值
	BTNode():data(),lchild(nullptr), rchild(nullptr){}
} BTNode;

// 线索二叉树结点定义
typedef struct TBTNode {
	int data;
	int ltag,rtag;
	struct TBTNode *lchild;
	struct TBTNode *rchild;
	TBTNode():data(),lchild(nullptr),rchild(nullptr){}
} TBTNode;

// 平衡二叉树结点定义
typedef struct AVLNode {
	int data;
	int balance; // 平衡因子
	struct AVLNode *lchild;
	struct AVLNode *rchild;
	AVLNode():data(),balance(),lchild(nullptr),rchild(nullptr){}
} AVLNode;

// 红黑树结点定义
typedef struct RBNode {
	int data;
	int color; // 颜色
	struct RBNode *lchild;
	struct RBNode *rchild;
	struct RBNode *parent;
	RBNode():data(),color(),lchild(nullptr),rchild(nullptr),parent(nullptr){}
} RBNode;
