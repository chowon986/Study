// 약수의 합2.cpp : https://www.acmicpc.net/problem/17427

#include <iostream>
// #include <vector>
using namespace std;

//int main()
//{
//	vector <long long > f(10000001, 1);
//
//	for (int i = 2; i < 1000001; i++)
//	{
//		for (int j = 1; i * j < 1000001; j++)
//		{
//			f[i * j] += i;
//		}
//	}
//
//	for (int i = 2; i < 1000001; i++)
//	{
//		f[i] = f[i - 1] + f[i];
//	}
//
//	int n;
//	cin >> n;
//
//	cout << f[n];
//}

int main()
{
	int n;
	cin >> n;
	long long sum = 0;

	for (int i = 1; i <= n; i++)
		sum += ((n / i) * i);

	cout << sum;
}