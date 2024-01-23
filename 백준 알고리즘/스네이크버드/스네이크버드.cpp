// 스네이크버드

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;

	vector<int> fruits;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		fruits.push_back(temp);
	}

	sort(fruits.begin(), fruits.end());

	for (int i = 0; i < n; i++)
	{
		if (l >= fruits[i])
			++l;
		else
			break;
	}
	cout << l;
}