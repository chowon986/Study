// 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	map<int, string> m1;
	map<string, int> m2;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		m1.insert({ i + 1, temp });
		m2.insert({ temp, i + 1 });
	}

	for (int i = 0; i < m; i++)
	{
		string temp;
		cin >> temp;

		if (isdigit(temp[0]))
		{
			auto j = m1.find(stoi(temp));
			cout << j->second << '\n';
		}
		else
		{
			auto j = m2.find(temp);
			cout << j->second << '\n';
		}
	}
}