/**
 * @author: SEKin 
 * @Date: 2023-04-23 23:23:45 
 * @description:  找顺序结构存储的二叉树的任意两节点的最近祖先节点
 * @Last Modified time: 2023-04-23 23:23:45 
 */

#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

int closeBTreePar(int i, int k){

	int h1 = log2(i) + 1;
	int h2 = log2(k) + 1;

	 while (h1!=h2)
	 {
		if(h2<h1 && h1 !=1){
			i = i /2;
			h1 = log2(i) + 1;
		}else if( h2!=1){
			k = k /2;
			h2 = log2(k) + 1;
		}
	 }

	 while (i!=k)
	 {
		i = i !=1 ? i/2 : 1;
		k=  k != 1 ? k/2 : 1;
	 }
	 return i;
}

int main(){
	int i, j;
	cin >>i >> j;
	int res = closeBTreePar(i,j);
	cout << "最近的祖先节点：" << res << endl;
	return 0;
}


