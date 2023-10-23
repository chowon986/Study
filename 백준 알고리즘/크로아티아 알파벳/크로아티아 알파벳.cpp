// 크로아티아 알파벳.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	string curWord = "";
	int count = 0;
	for (int i = 0; i < s.size(); i++)
	{
		curWord += s[i];

		if (curWord.size() == 3)
		{
			if (curWord == "dz=")
			{
				++count;
				curWord = "";
			}
			else
			{
				++count;
				string temp = curWord;
				curWord = temp[1];
				curWord += temp[2];
			}
		}

		if (curWord.size() == 2)
		{
			if (curWord == "c=" || curWord == "c-" || curWord == "d-" || curWord == "lj" || curWord == "nj" || curWord == "s=" || curWord == "z=")
			{
				++count;
				curWord = "";
			}
			else if (curWord != "dz")
			{
				++count;
				curWord = s[i];
			}
		}
	}

	if (curWord != "")
	{
		if (curWord == "c=" || curWord == "c-" || curWord == "d-" || curWord == "lj" || curWord == "nj" || curWord == "s=" || curWord == "z=")
		{
			++count;
		}
		else if (curWord == "dz=") ++count;
		else
			count += curWord.size();
	}

	cout << count;
}