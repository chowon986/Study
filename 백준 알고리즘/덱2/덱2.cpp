// 덱2.cpp 

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	deque<int> dq;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a;

		if (a == 1 || a == 2)
		{
			cin >> b;
		}

		if (a == 1)
		{
			dq.push_front(b);
		}
		else if (a == 2)
		{
			dq.push_back(b);
		}
		else if (a == 3)
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		}
		else if (a == 4)
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		else if (a == 5)
		{
			cout << dq.size() << '\n';
		}
		else if (a == 6)
		{
			if (dq.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (a == 7)
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.front() << '\n';
		}
		else if (a == 8)
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.back() << '\n';
		}
	}
}