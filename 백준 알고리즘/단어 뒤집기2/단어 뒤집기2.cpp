// 단어 뒤집기2.cpp

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	string curString;
	bool check = false;
	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] == '<')
			check = true;

		if (i == s.size())
		{
			reverse(curString.begin(), curString.end());
			cout << curString << ' ';
		}
		else if (s[i] == '>')
		{
			int temp = find(curString.begin(), curString.end(), '<') - curString.begin();

			for (int i = temp - 1; i >=0; i--)
				cout << curString[i];

			for (int i = temp; i < curString.size(); i++)
				cout << curString[i];

			cout << '>';
			curString = "";
			check = false;
		}

		else if (s[i] == ' ' && !check)
		{
			reverse(curString.begin(), curString.end());
			cout << curString << ' ';
			curString = "";
		}
		
		else
			curString += s[i];
	}
}