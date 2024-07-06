/**
 * @author: SEKin 
 * @Date: 2024-07-05 14:32:23 
 * @description:  插入类排序
 * @Last Modified time: 2024-07-05 14:32:23 
 */

// 直接插入排序
void InsertSort(int R[], int n){// n为 R的个数
	int i,j;
	int temp;
	for ( i = 1; i < n; i++) {
		temp = R[i];
		j = i -1;
		// 下面这个循环完成从待排序的关键字之前的开始扫描，
		while (j > 0 && temp < R[j]) {
			R[j + 1] = R[j];
			--j;
		}
		R[j+1] = temp; // 找到插入位置，将temp中暂存的插入
	}
}
