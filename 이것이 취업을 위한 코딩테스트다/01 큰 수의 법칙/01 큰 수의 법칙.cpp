// 01 큰 수의 법칙

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a[i] = temp;
	}

	sort(a.begin(), a.end(), greater<>());

	int count = 0;
	int ans = 0;
	int num1 = a[0];
	int num2 = a[1];

	count = m / (k + 1) * k; // num1의 개수
	count += m % (k + 1); // 나누어 떨어지지 않을 때 추가되는 num1의 개수

	ans += count * num1; // count만큼 num1을 곱해서 더해주고
	ans += (m - count) * num2; // 전체에서 count를 뺀 만큼 num2를 곱해서 더해주면 됨

	cout << ans;
}