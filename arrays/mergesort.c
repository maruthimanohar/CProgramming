#include<stdio.h>

void merge(int *arr, int start1, int end1, int start2, int end2) {
	int tmpelem = 
	while(start1 < end1 && start2 < end2) {
		if(arr[start1] > arr[start2]){
			swap(&arr[start1], &arr[start2]);
		}
		
	}
}

mergesort(int *arr, int start, int end ) {
	if (start == end) 
		return;
	while(start <= end) {
		int middle = ( start + end ) / 2;
		mergesort(arr, start, middle);
		mergesort(arr, middle+1, end);
		merge(arr, start, middle, middle+1, end);
	}
}
void main() {
	int arr[] = {4,5,3,1,8,9,10,12,2};
	mergesort(arr,0,8);
}
