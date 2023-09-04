// 00 순차 탐색

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	string target;
	cin >> n >> target;

	vector<string> v;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		if (v[i] == target)
			cout << i + 1;
	}
}