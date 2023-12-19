// 빈도 정렬

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> m2;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return m2.find(a.first)->second < m2.find(b.first)->second;

	return a.second > b.second;
}

int main()
{
	int n, c;
	cin >> n >> c;

	map<int, int> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		auto it = m.find(temp);

		if (it == m.end())
		{
			m.insert({ temp, 1 });
			m2.insert({ temp, i });
		}
		else
			it->second++;
	}

	vector<pair<int, int>> v2(m.begin(), m.end());
	sort(v2.begin(), v2.end(), cmp);

	for (auto& i : v2)
	{
		for (int j = 0; j < i.second; j++)
			cout << i.first << ' ';
	}
}