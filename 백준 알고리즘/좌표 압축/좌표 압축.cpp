// 좌표 압축

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> numbers;
	vector<int> sortedNumbers;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
		sortedNumbers.push_back(temp);
	}

	sort(sortedNumbers.begin(), sortedNumbers.end());
	sortedNumbers.erase(unique(sortedNumbers.begin(), sortedNumbers.end()), sortedNumbers.end());

	for (int i : numbers)
		cout << lower_bound(sortedNumbers.begin(), sortedNumbers.end(), i) - sortedNumbers.begin() << ' ';
}