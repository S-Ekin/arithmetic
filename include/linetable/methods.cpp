/**
 * @author: SEKin 
 * @Date: 2022-08-02 15:58:17 
 * @description: 一些算法问题
 * @Last Modified time: 2022-08-02 15:58:17 
 */
#include <stdlib.h>
#include <iostream>
#include "./linetable.h"
#include "./singleLink.cpp"
using namespace std;

//逆置数组
// 1、我自己
void cinOutArr(int arr[]){
	for (int i = 0; i < 7; i++)
	 {
		cout << arr[i] << " , " ;
	 }
	cout << endl;
}

void cinOutArr(LNode * a){
	a = a->next;
	while (a !=NULL)
	{
		cout << a->data << " , ";
		a = a->next;
	}
	
	cout << endl;
}
void  reserveArrAndChange(int arr[], int k, int n){
	for (int i = 0, j= k - 1; i < j; i++, j--)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	// 调换位置
	int d = n -k;
	int temp[n];
	for (int i = d; i < n; i++)
	{
		temp[i] = arr[i];
		int c = i - d;
		if(c < d){
			arr[i] = arr[c];
		} else {
			arr[i] = temp[c];
		}
	}
	//补上最后的空位
	for (int i = 0; i < d; i++)
	{
		arr[i] = temp[i+k];
	} 
	
	cinOutArr(arr);
}


// 划分
void partition(int arr[], int n){
	int i, j, temp;
	i = 0; 
	j = n - 1;
	temp = arr[0];

	while (i<j)
	{
		//先从右边j开始扫描，
		while (i< j && arr[j] >= temp) { j--; }
		// 腾出位置j
		if(i<j){
			arr[i] = arr[j];
			i++;
		}
		// 再扫描i
		while (i< j && arr[i] < temp) { i++; }
		// 腾出位置i
	   if(i<j){
			arr[j] = arr[i];
			j--;
		}
		
	}
	// 最后就是temp 的位置
	arr[i] = temp;
	

}

// 归并
void mergearray(){

}

// 差集
void subtraction(LNode *&A, LNode*B){
	LNode *a,*b,*r;
	a = A;
	b = B;
	cinOutArr(a);
	cinOutArr(b);

	a=a->next;
	b=b->next;

	A->next = NULL;
	r = A;

	free(B);
	while (a!=NULL)
	{
		while (b !=NULL && b->data < a->data)
		{
			b = b->next;
		}
		if(b == NULL || a == NULL){
			break;
		}
		if(b->data == a->data){
			r->next = a;
			r = r->next;
			b=b->next;
		} 
		a = a->next;
	}
	r->next = NULL; //记得断开和之前的连接
}

void testSubtraction(){
	int A[5] = {1,3,5,9,10};
	int B[8] = {-1,0,3,5,6,7,9,10};
	LNode *a, *b;
	createListR(a, A, 5);
	createListR(b, B, 8);
	subtraction(a,b);
	cinOutArr(a);
}

int main(){
	testSubtraction();
	return 0;
}
