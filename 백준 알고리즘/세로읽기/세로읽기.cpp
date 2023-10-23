// 세로읽기.cpp 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> words;

	for (int i = 0; i < 5; i++)
	{
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	int j = 0;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(words[j].size() > i)
				cout << words[j][i];
		}
	}
}