// [복습] N과 M (5)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;
bool isUsed[9];
int d[9];

void go(int index, int count)
{
	if (index == count)
	{
		for (int i = 0; i < index; i++)
		{
			cout << d[i] << ' ';
		}

		cout << '\n';
		return;
	}

	if (index > count) return;

	for (int i = 0; i < n; i++)
	{
		if (isUsed[i]) continue;

		isUsed[i] = true;
		d[index] = num[i];
		go(index + 1, count);
		isUsed[i] = false;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}

	sort(num.begin(), num.end());

	go(0, m);
}