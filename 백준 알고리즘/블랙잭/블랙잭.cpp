// 블랙잭.cpp

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int sum = 100000000;
	vector<int> numbers(n, 0);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers[i] = temp;
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int temp = numbers[i] + numbers[j] + numbers[k];
				if (m >= temp && (m - temp) < abs(m - sum))
				{
					sum = temp;
				}
			}
		}
	}

	cout << sum;
}