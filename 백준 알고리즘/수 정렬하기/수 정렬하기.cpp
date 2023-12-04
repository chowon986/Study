#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> numbers(n, 0);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers[i] = temp;
	}

	sort(numbers.begin(), numbers.end());

	for (int i : numbers)
	{
		cout << i << '\n';
	}
}