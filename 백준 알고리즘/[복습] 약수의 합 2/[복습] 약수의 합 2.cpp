// [복습] 약수의 합 2

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> numbers(n + 1);
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; i + j <= n; j += i)
		{
			sum += i;
		}
	}

	cout << sum;
}