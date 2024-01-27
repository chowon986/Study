#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	int cnt;
	cin >> cnt;

	deque<char> dq;
	string A, B;
	cin >> A;

	for (int i = 0; i < cnt; i++)
		dq.push_back(A[i]);

	string S;
	cin >> S;

	for (int i = 0; i < cnt; i++)
	{
		if (S[i] == 'L')
		{
			B += dq.front();
			dq.pop_front();
		}
		else if (S[i] == 'R')
		{
			B += dq.back();
			dq.pop_back();
		}
	}

	cout << B;
}