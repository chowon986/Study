// 팰린드롬수

#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
		string temp;
		cin >> temp;

		if (temp == "0")
			return 0;

		int lastIdx = temp.size() - 1;
		bool isTrue = true;
		for (int i = 0; i < temp.size() / 2; i++)
		{
			if (temp[i] != temp[lastIdx--])
			{
				cout << "no" << '\n';
				isTrue = false;
				break;
			}
		}

		if (isTrue)
			cout << "yes" << '\n';
	}
}