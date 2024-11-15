/**
 * @author: SEKin 
 * @Date: 2024-11-15 13:52:11 
 * @description:  线索二叉树
 * @Last Modified time: 2024-11-15 13:52:11 
 */

#include "../tree.h"
#include <iostream>
using namespace std;


void InThread(TBTNode *p,TBTNode *&pre){
  if(p!=NULL){
    InThread(p->lchild, pre); //递归，左子树线索化
    if(p->lchild == NULL){ //建立当前结点的前驱线索
      p->lchild = pre;
      p->ltag=1;
    }
    if(pre!=NULL && pre->rchild ==NULL){//建立当前结点的后继线索
      pre->rchild=p;
      pre->rtag=1;
    }
    pre=p; // pre指向当前的p,作为p将要指向的下一个结点的前驱结点指示指针
    p=p->rchild;//p指向一个新结点，此时pre和p分别指向的结点形成了一个前驱后继，为下一次线索的连接做准备
    InThread(p,pre);//递归，右子树线索化
  }
}


// 创建线索二叉树
	void createInThread(TBTNode *root){
  TBTNode *pre=NULL; //前驱结点指针
  if(root!=NULL){
    InThread(root,pre);
    pre->rchild=NULL;
    pre->rtag=1;
  }
}
