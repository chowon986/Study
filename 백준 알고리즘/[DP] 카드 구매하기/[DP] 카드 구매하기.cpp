﻿// [DP] 카드 구매하기

#include <iostream>
using namespace std;

int a[1001];
int d[1001];

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

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			d[i] = max(d[i], d[i - j] + a[j]);
	}

	cout << d[n];
}