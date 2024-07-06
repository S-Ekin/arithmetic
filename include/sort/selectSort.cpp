/**
 * @author: SEKin 
 * @Date: 2024-07-05 17:21:15 
 * @description:  选择排序
 * @Last Modified time: 2024-07-05 17:21:15 
 */

// 简单选择排序
void SelectSort(int R[], int n){
	int i,j,k;
	int temp;
	for ( i = 0; i < n; i++) {
		k = i;
		// 这个循环从无序序列中挑选出一个最小的关键字
		for ( j = i + 1; j < n; j++) {
			if(R[k] > R[j]){
				k = j;
			}
		}
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
}

/*
	堆排序
*/
// 结点调整函数，完成数组 low-high范围内对low 上的结点的调整。且调整的结构是循环向下的
void Sift(int R[], int low, int high){ // 这里关键字的存储设定为从数组下标1开始
	int i = low, j = 2 * i; // R[j]是R[i]的左孩子结点
	int temp = R[i];
	while (j<=high) {
		if(j < high && R[j] < R[j+1]) j++; // 如果右孩子较大的，则把j指向右孩子节点
		if(temp < R[j]){
			R[i] = R[j];
			i=j; // 修改 i 和 j 的值，以便继续向下调整
			j = 2 *i;
		} else {
			break;
		}
	}
	R[i] =  temp; // 被调整结点的值放入最终位置
}

// 堆排序函数
void  headSort(int R[], int n){
	int i;
	int temp;
	for ( i =  n/ 2; i > 1; --i) Sift(R, i ,n); //建立初始堆
	for (i = n; i >=2; --i) {
		temp = R[1];
		R[1] = R[i];
		R[i] = temp;
		Sift(R, 1, i -1); // 在减少了一个关键字的无序序列中进行调整
	}
}
