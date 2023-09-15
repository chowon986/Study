// [복습] N과 M (1)

#include <iostream>
using namespace std;

int d[9];
bool isUsed[9];
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
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if(isUsed[i] == false)
		{ 
			isUsed[i] = true;
			d[index] = i;
			go(index + 1, count);
			isUsed[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;

	go(0, m);
}