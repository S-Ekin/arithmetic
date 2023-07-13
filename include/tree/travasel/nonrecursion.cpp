/**
 * @author: SEKin 
 * @Date: 2023-04-24 16:37:17 
 * @description:  二叉树非递归遍历
 * @Last Modified time: 2023-04-24 16:37:17 
 */
#include "../basic/create.cpp"
#include <iostream>
#include <windows.h>
using std::cout;
using std::endl;

// 非递归后序遍历
void noneRePostVist(){
	
}


int main(int argc, char const *argv[])
{
	BTNode *tree;
	cout << "根结点：" << endl;
	createBT(tree);
	cout << tree->lchild->data << endl;
	noneRePostVist();
	return 0;
}

