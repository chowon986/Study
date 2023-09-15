// [복습] N과 M (2)

#include <iostream>
using namespace std;

int d[9];
bool isUsed[9];
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

	for (int i = start; i <= n; i++)
	{
		d[index] = i;
		go(index + 1, count, i + 1);
	}
}

int main()
{
	cin >> n >> m;

	go(0, m, 1);
}