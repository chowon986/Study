// 1, 2, 3 더하기(DP) : https://www.acmicpc.net/problem/9095

#include <iostream>
#include <vector>
using namespace std;

vector<int> d(12, 0);

int main()
{
	int tc;
	cin >> tc;

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= 11; i++)
	{
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}


	for (int i = 0; i < tc; i++)
	{
		int temp;
		cin >> temp;
		cout << d[temp] << '\n';
	}
}