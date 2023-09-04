// 01 삽입 정렬

#include <iostream>
using namespace std;

int a[] = { 7,5,9,0,3,1,6,2,4,8 };

int main()
{
	int size = sizeof(a) / sizeof(int);
	int idx = 1;

	for (int i = 0; i < size; i++)
	{
		int nIdx = i;
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[nIdx] < a[j])
			{
				swap(a[j], a[nIdx]);
				nIdx = j;
			}
			else break;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
}