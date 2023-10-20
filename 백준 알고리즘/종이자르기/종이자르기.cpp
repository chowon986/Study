#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n, m, cnt;
	cin >> n >> m >> cnt;

	vector<int> horizontal;
	vector<int> vertical;

	horizontal.push_back(0);
	horizontal.push_back(m);
	vertical.push_back(0);
	vertical.push_back(n);

	for (int i = 0; i < cnt; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0)
			horizontal.push_back(b);
		else
			vertical.push_back(b);
	}

	sort(horizontal.begin(), horizontal.end());
	sort(vertical.begin(), vertical.end());

	int maxSize = 0;
	for (int i = 1; i < vertical.size(); i++)
	{
		int x = 0; int y = 0;

		x = vertical[i] - vertical[i - 1];

		for (int j = 1; j < horizontal.size(); j++)
		{
			y = horizontal[j] - horizontal[j - 1];
			maxSize = max(maxSize, x * y);
		}
	}

	cout << maxSize;
}