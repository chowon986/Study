// 03 바닥 공사

#include <iostream>
using namespace std;

int d[1001];


int main()
{
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 3;

	for (int i = 1; i <= n; i++)
	{
		d[i] = (d[i - 1] + d[i - 2] * 2) % 796796;
	}

	cout << d[n];
}