// [복습] N과 M (6)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;
int d[9];
int n, m;

void go(int index, int count, int start)
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

	for (int i = start; i < n; i++)
	{
		d[index] = numbers[i];
		go(index + 1, count, i + 1);
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());

	go(0, m, 0);
}