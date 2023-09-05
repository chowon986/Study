// 00 피보나치 수열

#include <iostream>
using namespace std;

int d[100];

int go(int n)
{
	if (n == 1 || n == 2) return 1;

	if (d[n] != 0) return d[n];

	d[n] = go(n - 1) + go(n - 2);

	return d[n];
}

int main()
{
	int n;
	cin >> n;

	cout << go(n);
}