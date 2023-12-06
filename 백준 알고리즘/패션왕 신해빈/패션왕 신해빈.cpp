// 패션왕 신해빈

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		map<string, vector<string>> m;

		count += temp;

		for (int j = 0; j < temp; j++)
		{
			string a, b;
			cin >> a >> b;

			m[b].push_back(a);
		}

		int sum = 1;
		
		for (auto i : m)
		{
			sum *= (i.second.size() + 1);
		}

		cout << sum - 1 << '\n';
	}
}