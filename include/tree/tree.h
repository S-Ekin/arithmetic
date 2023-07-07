/**
 * @author: SEKin 
 * @Date: 2023-04-24 16:57:33 
 * @description:  树形结构定义
 * @Last Modified time: 2023-04-24 16:57:33 
 */

#pragma once
#define MaxSize 100

typedef struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode;

