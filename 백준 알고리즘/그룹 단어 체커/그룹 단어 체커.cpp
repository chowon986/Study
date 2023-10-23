// 그룹 단어 체커.cpp 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> alphabet(26);

void reset()
{
	for (int i = 0; i < 26; i++)
		alphabet[i] = false;
}

int main()
{
	int n;
	cin >> n;

	vector<string> words;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		words.push_back(temp);
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		reset();
		bool isFail = false;
		char prevWord = words[i][0];
		alphabet[words[i][0] - 'a'] = true;
		for (int j = 1; j < words[i].size(); j++)
		{
			if (prevWord != words[i][j])
			{
				if (alphabet[words[i][j] - 'a'] == true)
				{
					isFail = true;
					break;
				}
				
				prevWord = words[i][j];
				alphabet[words[i][j] - 'a'] = true;
			}
		}

		if (!isFail) ++count;
	}

	cout << count;
}