// 단어 공부.cpp 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> alphabet(26, 0);

int main()
{
	string s;
	cin >> s;

	int maxCount = 0;

	for (int i = 0; i < s.size(); i++)
	{
		int temp = toupper(s[i]) - 'A';
		++alphabet[temp];

		maxCount = max(maxCount, alphabet[temp]);
	}

	int count = 0;
	int num = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == maxCount)
		{
			++count;
			num = i;
		}
	}

	if (count >= 2) cout << '?';
	else cout << (char)(num + 'A');

}