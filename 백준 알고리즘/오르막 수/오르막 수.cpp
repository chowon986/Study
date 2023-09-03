// 이전 풀이

//// https://www.acmicpc.net/problem/11057
//
//#include <iostream>
//
//using namespace std;
//
//int D[1001][10];
//
//int main()
//{
//	int N;
//	cin >> N;
//
//	for (int i = 0; i < 10; i++)
//	{
//		D[0][i] = 1;
//	}
//
//	int Sum = 0;
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			for (int k = 0; k <= j; k++)
//			{
//				D[i][j] += D[i - 1][k] % 10007;
//			}
//		}
//	}
//
//	cout << D[N][9] % 10007;
//}

// 시간 초과 풀이

//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> d;
//int sum = 0;
//
//void go(int index, int start, int count)
//{
//	if (index > 0)
//		if (start < d[index - 1]) return;
//
//	if (index == count)
//	{
//		++sum;
//
//		if (sum > 10007)
//			sum %= 10007;
//
//		return;
//	}
//
//	if (index > count) return;
//
//	for (int i = start; i < 10; i++)
//	{
//		d[index] = i;
//		go(index + 1, i, count);
//	}
//}
//
//int main()
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//	d.resize(n);
//
//	go(0, 0, n);
//	cout << sum % 10007;
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> numbers;

	for (int i = 0; i < n; i++)
	{
		numbers.push_back(0);
	}

	int count = 0;

	while (true)
	{
		bool isTrue = true;
		if (numbers.front() == 10) break;

		++numbers.back();


		for (int i = n - 1; i > 0; i--)
		{
			if (numbers[i] == 10)
			{
				++numbers[i - 1];
				numbers[i] = 0;
			}
		}

		for (int i = n - 1; i > 0; i--)
		{
			if (numbers[i] < numbers[i - 1])
			{
				isTrue = false;
				break;
			}
		}

		if(isTrue) ++count;
	}

	int ans =  n == 1 ? count : count + 1;
	cout << ans % 10007;
}