/**
 * @author: SEKin 
 * @Date: 2022-08-02 15:58:17 
 * @description: 一些算法问题
 * @Last Modified time: 2022-08-02 15:58:17 
 */
#include <stdlib.h>
#include <iostream>
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

int main(){
	int arr [7] = {1,2,3,4,5,6,7};
	reserveArrAndChange(arr, 5, 7);
	cinOutArr(arr);
	return 0;
}
