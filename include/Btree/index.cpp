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
#include "./travasel/levVist.cpp"
#include "./problem/search.cpp"
using std::cout;
using std::endl;


// 遍历
void visit(){
	// BTNode *tree = (BTNode *)malloc(sizeof(BTNode)); //这样创建的指针 在结构类型里设置的初始化值 没有用
	BTNode *tree = new BTNode;
	bool res = tree->lchild == nullptr;
	cout << tree->data <<( res ? "true" : "false") << endl;
	createBTByArr(tree);
	preVist(tree);
	cout << endl;
	levVist(tree);
	cout << endl;

	BTNode *tree2 = new BTNode;
	bool res2 = tree2->lchild == nullptr;
	cout << tree2->data <<( res2 ? "true" : "false") << endl;
}

void test(){
	BTNode *tree = new BTNode;
	nonReCreateBTByTravasel(tree);
	preVist(tree);
	cout << endl;
	midVist(tree);
	cout << endl;
}

void test2(){
	BTNode *tree = new BTNode;
	createBTByArr(tree);
	bool res = isCompeleteBT(tree);
	const char *tip = res ? "是完全" : "不是";
	cout << tip << endl;
}


int main(){
	test2();
	system("pause");
	return 0;
}
