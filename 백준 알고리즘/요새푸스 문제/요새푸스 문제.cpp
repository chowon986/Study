// 요새푸스 문제

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> numbers;

	for (int i = 1; i <= n; i++)
		numbers.push(i);

	int cnt = 0;

	cout << '<';

	while (!numbers.empty())
	{
		++cnt;
		if (cnt < k)
		{
			numbers.push(numbers.front());
			numbers.pop();
		}
		else if (cnt == k)
		{
			if (numbers.size() != 1)
				cout << numbers.front() << ", ";
			else
				cout << numbers.front();
			numbers.pop();

			cnt = 0;
		}
	}

	cout << '>';
}