/**
 * @author: SEKin 
 * @Date: 2024-07-06 10:36:22 
 * @description:  二路归并算法
 * @Last Modified time: 2024-07-06 10:36:22 
 */

#include <iostream>

using std::cout;
using std::endl;

// 归并函数，把A数组中low到mid 和 mid+1 到high 范围内的两端有序序列归并为一段有序序列
// 合并两个已排序的子数组
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // 左半部分的长度
    int n2 = right - mid; // 右半部分的长度

    // 创建临时数组存储左右子数组，一定要定义数组大小，否则会出现数组越界的情况
    int L[n1] = {};
    int R[n2] = {};

    // 复制数据到临时数组L[]和R[]
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    // 合并临时数组到原数组中
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // 复制L[]的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // 复制R[]的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

}


void mergeSort(int A[], int low, int high){
	if(low < high){
		int mid = (low + high) / 2;
		mergeSort(A, low, mid);
		mergeSort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}


// 测试函数
int main() {
    int arr[6] = {12, 11, 13, 5, 6, 7};
    cout << "Given array is \n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

	int n = 6;
    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array is \n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
