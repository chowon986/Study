// 스택2.cpp

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 1)
		{
			int newValue;
			cin >> newValue;
			s.push(newValue);
		}
		else if (temp == 2)
		{
			if (!s.empty())
			{
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
		else if (temp == 3)
		{
			cout << s.size() << '\n';
		}
		else if (temp == 4)
		{
			if (!s.empty())
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (temp == 5)
		{
			if (!s.empty())
			{
				cout << s.top() << '\n';
			}
			else
				cout << -1 << '\n';
		}
	}
}