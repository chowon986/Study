// 02 개미 전사

#include <iostream>
using namespace std;

int d[101];
int a[101];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	d[1] = a[1];

	for (int i = 2; i <= n; i++)
	{
		d[i] = max(d[i - 1], d[i - 2] + a[i]);
	}

	cout << d[n];
}