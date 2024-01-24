// 카드1

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int n;
	cin >> n;

	deque<int> dq;

	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	while (!dq.empty())
	{
		cout << dq.front() << ' ';
		dq.pop_front();

		if (dq.empty())
			break;

		int temp = dq.front();
		dq.push_back(temp);
		dq.pop_front();
	}
}