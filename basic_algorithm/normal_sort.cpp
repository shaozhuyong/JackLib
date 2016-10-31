// c_plus_plus_demo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/// <summary>
/// ����ð�������㷨
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
/// ���������㷨,��ð������ĸĽ�
/// </summary>
/// <param name="data"></param>
/// <param name="left">����ķ�Χ���±�</param>
/// <param name="right">����ķ�Χ���±�</param>
void QuickSort(int* data,int left,int right) {
	if (left < right) {
		//1 �����㷨��low=��һ��Ԫ�ص��±꣬high=���һ��Ԫ�ص��±꣬currentValue =��һ��Ԫ��
		int low = left, high = right, currentValue = data[left];

		while (low < high) {
			//2 ���ҵ�����ұȵ�ǰ��׼ֵС��ֵ
			while (low < high && data[high] > currentValue) {
				high--;
			}
			//3 �ҵ����±�Ϊhigh��ֵ���±�Ϊlow��ֵ
			data[low] = data[high];

			//4 �����Ҳ��ұȵ�ǰ��׼ֵ���ֵ
			while (low < high && data[low] < currentValue) {
				low++;
			}
			//5 �ҵ����±�Ϊlow��ֵ���±�Ϊhigh��ֵ
			data[high] = data[low];
		}

		//һ�ֱȽ���ɣ�����׼ֵ���±�Ϊlow��ֵ
		data[low] = currentValue;
		QuickSort(data, left, low - 1);
		QuickSort(data, low + 1, right);
	}
}

/*
int main(int argc, char* argv[]) {	
	int student[10]= {10,9,8,7,6,5,4,3,2,1};
	//ð������
	BubbleSort(student,0,9);
	//��������
	QuickSort(student,0,9);
	system("pause");
	return 0;
}*/

