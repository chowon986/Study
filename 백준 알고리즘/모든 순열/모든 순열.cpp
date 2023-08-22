// 모든 순열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> numbers;

	for (int i = 1; i <= n; i++)
	{
		numbers.push_back(i);
	}

	do
	{
		for (int i = 0; i < n; i++)
		{
			cout << numbers[i] << ' ';
		}

		cout << '\n';
	} while (next_permutation(numbers.begin(), numbers.end()));

}