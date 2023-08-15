// 약수의 합.cpp : https://www.acmicpc.net/problem/17425

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int max = 1000001;
	vector <long long> g(max, 1);

	for (int i = 2; i < max; i++)
	{
		for (int j = 1; i * j < max; j++)
			g[i * j] += i;
	}

	for (int i = 2; i < max; i++)
		g[i] = g[i] + g[i - 1];

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int num;
		cin >> num;
		cout << g[num] << '\n';
	}
}