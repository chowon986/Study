// 부분수열의 합

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ans = 0;
	int n;
	int s;
	cin >> n >> s;

	vector<int> a(n, 0);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	for (int i = 1; i < (1 << n); i++)
	{
		int sum = 0;

		for (int k = 0; k < n; k++)
		{
			if (i & (1 << k)) // 비트 마스크 i에 k가 들어있는지 확인
			{
				sum += a[k];
			}
		}

		if (sum == s)
		{
			ans += 1;
		}
	}

	cout << ans;
}