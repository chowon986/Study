// 03 계수 정렬

#include <iostream>
#include <vector>
using namespace std;

int a[] = { 7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2 };

int main()
{
	vector<int> v(10, 0);

	int size = sizeof(a) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		++v[a[i]];
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i]; j++)
		{
			cout << i << ' ';
		}
	}
}