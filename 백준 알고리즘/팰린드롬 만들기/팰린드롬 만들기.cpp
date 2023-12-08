// 팰린드롬 만들기

// 시간 초과
//int main()
//{
	//string s;
	//cin >> s;

	//sort(s.begin(), s.end());

	//do
	//{
	//	string temp = s;
	//	reverse(temp.begin(), temp.end());

	//	if (s == temp)
	//	{
	//		cout << s;
	//		return 0;
	//	}

	//} while (next_permutation(s.begin(), s.end()));

	//cout << "I'm Sorry Hansoo";
//}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int alpha[26] = { 0, };
	
	for (char i : s)
	{
		++alpha[i - 'A' ];
	}

	int oddCount = 0;
	for (int i : alpha)
	{
		if (i % 2 != 0)
			++oddCount;
	}

	if (oddCount > 1)
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	char oneWord = ' ';
	string answer = "";

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] == 0) continue;

		char temp = i + 'A';
		if (alpha[i] %2 == 1)
		{
			oneWord = temp;
		}

		int maxIdx = alpha[i] / 2;

		for (int j = 0; j < maxIdx; j++)
			answer += temp;
	}

	string temp = answer;
	reverse(temp.begin(), temp.end());

	if (oneWord != ' ')
		answer += oneWord;

	answer += temp;
	cout << answer;
}
