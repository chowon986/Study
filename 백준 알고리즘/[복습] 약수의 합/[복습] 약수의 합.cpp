// [복습] 약수의 합

#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(MAX + 1, 1);
	vector<long long> d(MAX + 1);
	a[0] = 0;

	for (int i = 2; i <= MAX; i++)
	{
		for (int j = 0; i + j <= MAX; j += i)
			a[i + j] += i;
	}
	
	for (int i = 1; i <= MAX; i++)
	{
		d[i] = d[i - 1] + a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		cout << d[temp] << '\n';
	}
}