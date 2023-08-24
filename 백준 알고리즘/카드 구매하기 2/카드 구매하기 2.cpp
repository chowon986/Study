// 카드 구매하기 2 : https://www.acmicpc.net/problem/16194

#include <iostream>
#include <vector>
using namespace std;

vector<int> d(1001);
vector<int> p(1001);

int main()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		int temp;
		cin >> temp;
		p[i] = temp;
		d[i] = temp;
	}

	for (int i = 1; i <= tc; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = min(d[i], d[i - j] + p[j]);
		}
	}

	cout << d[tc];
}