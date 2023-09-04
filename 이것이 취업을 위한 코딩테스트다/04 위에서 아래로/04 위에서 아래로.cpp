// 04 위에서 아래로

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> d(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		d[i] = temp;
	}

	sort(d.begin(), d.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		cout << d[i] << ' ';
	}
}