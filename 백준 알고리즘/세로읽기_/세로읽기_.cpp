#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string temp = "";

	vector<string> allWords;

	for(int i = 0; i < 5; i++)
	{
		cin >> temp;
		allWords.push_back(temp);
	}

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (allWords[i].size() > j)
				cout << allWords[i][j];
		}
	}
}