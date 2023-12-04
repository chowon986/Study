// 덩치.cpp 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	for (int i = 0; i < n; i++)
	{
		int rank = 1;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				++rank;
		}
		cout << rank << ' ';
	}
}