/**
 * @author: SEKin 
 * @Date: 2024-07-27 09:55:25 
 * @description:  基础查找方法
 * @Last Modified time: 2024-07-27 09:55:25 
 */


// 折半查找
int Bsearch(int R[], int low, int high, int k){
	int mid;
	while(low<=high){
		mid = (low+high)/2;
		if(R[mid]== k){
			return mid;
		} else if(R[mid]>k){
			high = mid - 1;
		} else {
			low = mid+1;
		}
	}
	return 0;
}

