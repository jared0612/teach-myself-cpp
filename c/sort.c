/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Sep 2022 12:06:12 AM CST
 ************************************************************************/

#include<stdio.h>

//选择排序，选择排序和插入排序正好是相反，他是从待排序中选择最值加入到已排序中，
//假设初始都是未排序的，先选择最小的放在最左边， 然后从右边在选择最小指。
void select_sort(int arr[], int len) {
	for (int i = 0; i < len - 1; ++i) {
		int min = i;
		for (int j  = i + 1; j < len; ++j) {
			if (arr[j] < arr[min] ) {
				min = j;
			}
		}
		if (arr[min] < arr[i]) {
			arr[min] += arr[i];
			arr[i] = arr[min] - arr[i];
			arr[min] = arr[min] - arr[i];
		}
	}
}








//插入排序，从待排序中插入到已排序的区间中，默认已排序大小为1；
void insert_sort(int arr[], int len) {
	for (int i = 1; i < len; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}







//冒泡排序；两重循环，两两进行比较,从小到大排序
void bubble_sort(int arr[], int len) {
	int i, j, temp;
	for (i = 0; i < len - 1; i++) {
		for(j = 1; j < len - i; j++) {
			if (arr[j - 1] > arr[j] ) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}
void print(int arr[], int len) {
	printf("arr(%d) : [", len);
	for (int i = 0; i < len; ++i) {
		i ? printf(" %d",arr[i]) : printf("%d", arr[i]);
	}
	printf("]\n");
}

int main() {
	int arr[8] = {1, 12, 56, 2, 5, 3, 23,14};
	size_t len = sizeof(arr) / sizeof(int);
	//bubble_sort(arr, len);
	//insert_sort(arr, len);
	select_sort(arr, len);
	print(arr, len);
	return 0;
}

