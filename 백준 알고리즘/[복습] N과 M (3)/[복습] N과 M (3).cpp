// [복습] N과 M (3)

#include <iostream>
using namespace std;

int d[8];
int n, m;

void go(int index, int count)
{
	if (index == count)
	{
		for (int i = 0; i < index; i++)
		{
			cout << d[i] << ' ';
		}

		cout << '\n';
	}

	if (index > count) return;

	for (int i = 1; i <= n; i++)
	{
		d[index] = i;
		go(index + 1, count);
	}
}

int main()
{
	cin >> n >> m;

	go(0, m);
}