// 1, 2, 3 더하기.cpp : https://www.acmicpc.net/problem/9095

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int tc;
	cin >> tc;

	vector<int> g(12, 0);
	g[0] = 0;
	g[1] = 1;
	g[2] = 2;
	g[3] = 4;

	for (int i = 4; i < 12; i++)
	{
		g[i] = g[i - 1] + g[i - 2] + g[i - 3];
	}

	for (int i = 0; i < tc; i++)
	{
		int temp;
		cin >> temp;
		cout << g[temp] << '\n';
	}
}