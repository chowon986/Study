// [복습] 소수 찾기

#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000

vector<bool> d(MAX + 1, true);

bool IsPrime(int num)
{
	return d[num];
}

int main()
{
	int n;
	cin >> n;
	int count = 0;

	d[0] = d[1] = false;

	for (int i = 2; i <= MAX; i++)
	{
		for (int j = i; i + j <= MAX; j += i)
		{
			if (d[i + j]) d[i + j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (IsPrime(temp)) ++count;
	}

	cout << count;
}