// 01 이진 탐색

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, target;
vector<int> b;

void go(int start, int end)
{
	if (start > end)
	{
		cout << "원소가 존재하지 않습니다.";
		return;
	}

	int mid = (end + start) / 2;

	if (b[mid] == target)
	{
		cout << mid + 1;
		return;
	}
	else if (b[mid] < target)
	{
		go(mid + 1, end);
	}
	else if (b[mid] > target)
	{
		go(start, mid - 1);
	}
}

int main()
{
	cin >> n >> target;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		b.push_back(temp);
	}

	sort(b.begin(), b.end());

	int start = 0;
	int end = b.size() - 1;

	go(start, end);
}