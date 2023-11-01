// 스택 수열.cpp 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<bool> isVisited(100001, false);

int main()
{
	isVisited[0] = true;
	vector<char> ans;

	int n;
	cin >> n;

	int curPos = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (isVisited[temp])
		{
			cout << "NO";
			return 0;
		}

		if (!isVisited[temp])
		{
			while (curPos < temp)
			{
				++curPos;
				if(!isVisited[curPos])
					ans.push_back('+');
			}

			while (curPos >= temp)
			{
				if (!isVisited[curPos])
				{
					isVisited[curPos] = true;
					ans.push_back('-');
				}
				--curPos;
			}
		}
	}

	for (auto i : ans)
		cout << i << '\n';
}