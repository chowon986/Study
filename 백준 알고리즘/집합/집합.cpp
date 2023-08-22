// 집합

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int ans = 0;

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		string word;
		int value;
		cin >> word;
		if (word != "all" && word != "empty")
			cin >> value;

		if (word == "add")
		{
			ans |= (1 << value);
		}
		else if (word == "remove")
		{
			ans &= ~(1 << value);
		}
		else if (word == "check")
		{
			if (ans & (1 << value))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (word == "toggle")
		{
			ans ^= (1 << value);
		}
		else if (word == "all")
		{
			ans = (1 << 21) - 1;
		}
		else if (word == "empty")
		{
			ans = 0;
		}
	}
}