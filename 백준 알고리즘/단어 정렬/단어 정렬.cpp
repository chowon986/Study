// 단어 정렬.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool checkSize(const string& a, const string& b)
{
	if (a.size() == b.size())
		return a < b;

	return a.size() < b.size();
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

	sort(words.begin(), words.end(), checkSize);
	words.erase(unique(words.begin(), words.end()), words.end());

	for (auto i : words)
		cout << i << '\n';
}