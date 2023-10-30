// 좌표 정렬하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> numbers(n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		numbers[i] = make_pair(a, b);
	}

	sort(numbers.begin(), numbers.end(),cmp);
	
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i].first << ' ' << numbers[i].second << '\n';
	}
}