// 00 선택 정렬

// 배열 중에서 가장 작은 수를 찾은 다음 인덱스 i번째와 swap

#include <iostream>
using namespace std;

int a[] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

int main()
{
	int size = sizeof(a) / sizeof(int);
	int idx = 0;

	for (int i = 0; i < size; i++)
	{
		int minValue = 1000000;
		int minIdx = -1;
		for (int j = i; j < size; j++)
		{
			if (minValue > a[j])
			{
				minIdx = j;
				minValue = a[j];
			}
		}

		swap(a[idx++], a[minIdx]);
	}

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
}