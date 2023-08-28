// 이전 풀이

//#include <iostream>
//#include <vector>
//
//#define MAX 1000001
//#define MOD 1000000009
//
//using namespace std;
//
//int main()
//{
//	int Cnt;
//	cin >> Cnt;
//
//	vector<int> D(MAX, 0);
//
//	D[0] = 1;
//
//	for (int i = 1; i < MAX; i++)
//	{
//		if (i - 1 >= 0)
//			D[i] += D[i - 1];
//
//		if (i - 2 >= 0)
//			D[i] += D[i - 2];
//
//		D[i] %= MOD;
//
//		if (i - 3 >= 0)
//			D[i] += D[i - 3];
//
//		D[i] %= MOD;
//
//	}
//
//	for (int i = 0; i < Cnt; i++)
//	{
//		int Num;
//		cin >> Num;
//		cout << D[Num] << '\n';
//	}
//}

// 1, 2, 3 더하기 3 : https://www.acmicpc.net/problem/15988

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int cnt;

	cin >> cnt;

	vector<long long> d(1000001, 0);

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	
	for (int i = 3; i < 1000001; i++)
	{
		d[i] = ((d[i - 1] % 1000000009) + (d[i - 2] % 1000000009) + (d[i - 3] % 1000000009)) % 1000000009;
	}

	for (int i = 0; i < cnt; i++)
	{
		int temp;
		cin >> temp;
		cout << d[temp] << '\n';
	}
}