/**
 * @author: SEKin
 * @Date: 2024-07-05 15:37:43
 * @description:  交换排序
 * @Last Modified time: 2024-07-05 15:37:43
 */

// 冒泡排序

void BubbleSort(int R[], int n) {
	int i, j, flag;
	int temp;
	for (i = n - 1; i >= 1; i--) {
		flag = 0; // 用来标记本趟排序是否发生交换
		for (j = 1; j < i; ++j) {
			if (R[j - 1] > R[j]) {
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				flag = 1;
			}
		}

		if (flag == 0) {
			return;
		}
	}
}

// 快速排序
void QuickSort(int R[], int low , int high){
  // 对R[low] 到 R[high] 的关键字排序
  int temp;
  int i = low, j = high;
  if(low < high){
	temp = R[low];
	// 下面的循环完成一趟排序，将小于temp的放左边，大于的放右边
	while(i<j){
		while (j<i && R[j] >= temp) --j; // 从右往左扫描，找到一个小于temp的关键字
		if(i<j){
			R[i] = R[j]; // 放在 temp 左边
			++i;
		}
		while (i<j && R[i] < temp) ++i; // 从左往右扫描，找到一个大于 temp的关键字
		if(i<j){
			R[j] = R[i]; // 放在temp 右边
			--j;
		}
	}
	R[i] = temp; // 将temp 放在最终位置
	QuickSort(R, low, i - 1); // 递归对temp 左边的关键字进行排序
	QuickSort(R, i + 1, high); // 递归对temp 右边的关键字进行排序
  }
}
