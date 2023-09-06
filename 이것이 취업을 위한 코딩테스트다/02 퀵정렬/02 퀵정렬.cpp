// 02 퀵정렬

#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void quickSort(int start, int end)
{
	// 원소가 하나인 경우 종료
	if (start >= end) return;

	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && a[left] <= a[pivot])
			++left;

		while (right > start && a[right] >= a[pivot])
			--right;

		if (left > right) // 원소가 엇갈리면 작은값과 pivot 변경
			swap(a[pivot], a[right]);
		else			  // 아니면 left와 right 변경
			swap(a[left], a[right]);
	}

	quickSort(start, right - 1);
	quickSort(right + 1, end);
}

int main()
{
	a = { 5, 7, 9, 0, 3, 1, 6, 2, 4, 8 };

	int start = 0;
	int end = a.size() - 1;

	quickSort(start, end);

	for (int i : a)
	{
		cout << i << '\n';
	}
}