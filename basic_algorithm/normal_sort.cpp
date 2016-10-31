// c_plus_plus_demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/// <summary>
/// 经典冒泡排序算法
/// </summary>
/// <param name="data"></param>
void BubbleSort(int* data,int left,int right) {
	for (int i = left; i < right + 1; i++) {
		for (int j = i; j < right + 1; j++) {
			if (data[i] > data[j]) {
				int tem = data[i];
				data[i] = data[j];
				data[j] = tem;
			}
		}
	}
}

/// <summary>
/// 快速排序算法,对冒泡排序的改进
/// </summary>
/// <param name="data"></param>
/// <param name="left">排序的范围左下标</param>
/// <param name="right">排序的范围右下标</param>
void QuickSort(int* data,int left,int right) {
	if (left < right) {
		//1 快排算法：low=第一个元素的下标，high=最后一个元素的下标，currentValue =第一个元素
		int low = left, high = right, currentValue = data[left];

		while (low < high) {
			//2 从右到左查找比当前基准值小的值
			while (low < high && data[high] > currentValue) {
				high--;
			}
			//3 找到后将下标为high的值给下标为low的值
			data[low] = data[high];

			//4 从左到右查找比当前基准值大的值
			while (low < high && data[low] < currentValue) {
				low++;
			}
			//5 找到后将下标为low的值给下标为high的值
			data[high] = data[low];
		}

		//一轮比较完成，将基准值给下标为low的值
		data[low] = currentValue;
		QuickSort(data, left, low - 1);
		QuickSort(data, low + 1, right);
	}
}

/*
int main(int argc, char* argv[]) {	
	int student[10]= {10,9,8,7,6,5,4,3,2,1};
	//冒泡排序
	BubbleSort(student,0,9);
	//快速排序
	QuickSort(student,0,9);
	system("pause");
	return 0;
}*/

