// 큐2

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		if (temp == "push")
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (temp == "pop")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << q.front() << '\n';
			q.pop();
		}
		else if (temp == "size")
		{
			if (q.empty())
			{
				cout << 0 << '\n';
			}
			else
				cout << q.size() << '\n';
		}
		else if (temp == "empty")
		{
			if (q.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (temp == "front")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << q.front() << '\n';
		}
		else if (temp == "back")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << q.back() << '\n';
		}
	}
}