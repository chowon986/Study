// 제로.cpp

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> s;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			sum -= s.top();
			s.pop();
		}
		else
		{
			sum += temp;
			s.push(temp);
		}
	}

	cout << sum;
}