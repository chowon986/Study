// 수 이어 쓰기 1.cpp : https://www.acmicpc.net/problem/1748

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	// 1 - 9     1자리
	// 10 - 99   2자리
	// 100 - 999 3자리

	long long ans = 0;

	for (int start = 1, len = 1; start <= n; start *= 10, len++)
	{
		int end = start * 10 - 1;
		if (end > n) end = n;
		ans += (long long)(end - start + 1) * len;
	}

	cout << ans << '\n';
}