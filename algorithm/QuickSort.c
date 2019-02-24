/*
	2019年2月24日21:25:06
	快排：分两部分，找到一个比 mid小的数，和一个比 mid大的数，交换，
	循环再从两边找 2个数继续交换。
	直到 min 跟 max 交叉，一边的数完全比另一边的小
	然后递归分别进入每一边， 再重复找数
*/


#include <stdio.h>

void QuickSort(int * arr, int iMin, int iMax) {
	
	int min = iMin;
	int max = iMax;
	int mid = arr[min+(max-min)/2];
	int temp;
	
	while(min <= max)
	{
		while (min <= iMax && arr[min] < mid)
			min++;
		while (max >= iMin && arr[max] > mid)
			max--;
		if(min <= max)
		{
			temp = arr[min];
			arr[min] = arr[max];
			arr[max] = temp;
			
			min++;
			max--;
		}
	}
	
	if(min < iMax) QuickSort(arr, min, iMax);
	if(max > iMin) QuickSort(arr, iMin, max);
}

 int main() {
	
	int arr[10];
	
	for(int i=0; i<10; i++)
		scanf("%d", &arr[i]);
	
	QuickSort(arr, 0, 9);
	
	for(int i=0; i<10; i++)
		printf("%d ", arr[i]);
	
 	return 0;
 }
