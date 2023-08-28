// 0827 복습_DP

// 1로 만들기 : https://www.acmicpc.net/problem/1463

// 2xn 타일링 : https://www.acmicpc.net/problem/11726

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<int> d(n + 1, 0);
//
//	d[0] = 1;
//	d[1] = 1;
//
//	for (int i = 2; i <=  n; i++)
//	{
//		d[i] = (d[i - 1] + d[i - 2] ) % 10007;
//	}
//
//	cout << d[n];
//}

// 2xn 타일링 2 : https://www.acmicpc.net/problem/11727

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<int> d(n + 1, 0);
//
//	d[0] = 1;
//	d[1] = 1;
//	d[2] = 3;
//
//	for (int i = 3; i <= n; i++)
//	{
//		d[i] = (d[i - 1] + (d[i - 2] * 2)) % 10007;
//	}
//
//	cout << d[n];
//}

// 1, 2, 3 더하기 : https://www.acmicpc.net/problem/9095

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int cnt;
//	cin >> cnt;
//
//	vector<int> d(12, 0);
//
//	d[0] = d[1] = 1;
//	d[2] = 2;
//	d[3] = 4;
//
//	for (int i = 4; i <= 11; i++)
//	{
//		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
//	}
//
//	for (int i = 0; i < cnt; i++)
//	{
//		int temp;
//		cin >> temp;
//		cout << d[temp] << '\n';
//	}
//}

// 카드 구매하기 : https://www.acmicpc.net/problem/11052

// 카드 구매하기 2 : https://www.acmicpc.net/problem/16194

// 1, 2, 3, 더하기 5 : https://www.acmicpc.net/problem/15990

// 쉬운 계단 수 : https://www.acmicpc.net/problem/10844

// 이친수 : https://www.acmicpc.net/problem/2193

// 가장 긴 증가하는 부분 수열 : https://www.acmicpc.net/problem/11053

// 가장 긴 증가하는 부분 수열 4 : https://www.acmicpc.net/problem/14002

// 연속합 : https://www.acmicpc.net/problem/1912

// 제곱수의 합 : https://www.acmicpc.net/problem/1699

// 퇴사 : https://www.acmicpc.net/problem/14501

// 합분해 : https://www.acmicpc.net/problem/2225

int main()
{

}
