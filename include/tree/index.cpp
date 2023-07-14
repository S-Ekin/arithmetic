/**
 * @author: SEKin 
 * @Date: 2023-04-23 21:54:36 
 * @description:  树和二叉树
 * @Last Modified time: 2023-04-23 21:54:36 
 */
#include <iostream>
#include "./basic/create.cpp"
#include "./travasel/nonrecursion.cpp"
#include "./travasel/recursion.cpp"
using std::cout;


// 遍历
void visit(){
	BTNode *tree = (BTNode *)malloc(sizeof(BTNode));
	createBTByArr(tree);
	// postVist(tree);
	cout << endl;
	// noneRePostVist(tree);
	cout << endl; 
}


int main(){
	visit();
	system("pause");
	return 0;
}
