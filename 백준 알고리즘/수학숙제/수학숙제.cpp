// 수학숙제
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void deleteZero(string& s)
{
	while (s.size() > 0 && s[0] == '0')
	{
		s.erase(s.begin());
	}

	if (s.size() == 0)
		s = "0";
}

bool cmp(string& a, string& b)
{
	if (a.size() == b.size())
		return a < b;

	return a.size() < b.size();
}

int main()
{
	int n;
	cin >> n;

	vector<string> ans;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		string curNum = "";
		int size = s.size();

		for (int i = 0; i < size; i++)
		{
			if (isdigit(s[i]))
			{
				curNum += s[i];

				if (i == size - 1)
				{
					if (curNum[0] == '0')
						deleteZero(curNum);

					ans.push_back(curNum);
				}
			}
			else
			{
				if (curNum != "")
				{
					if (curNum[0] == '0')
						deleteZero(curNum);

					ans.push_back(curNum);
					curNum = "";
				}
			}
		}
	}

	sort(ans.begin(), ans.end(), cmp);

	for (auto i : ans)
		cout << i << '\n';
}