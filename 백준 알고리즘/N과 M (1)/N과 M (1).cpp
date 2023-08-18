// N과 M (1) : https://www.acmicpc.net/problem/15649

// 변하는 값 : 위치, 사용 가능한 수
// 변하는 값이 인자로 들어가야 함

//#include <vector>
//#include <iostream>
//using namespace std;
//
//vector<bool> c(10, false); // 앞에서 사용한 수인지?
//vector<int> a(10, false); // 수열을 저장
//
//void go(int index, int n, int m)
//{
//	if (index == m)
//	{
//		for (int i = 0; i < index; i++)
//		{
//			cout << a[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		if (c[i]) continue;
//		c[i] = true;
//		a[index] = i;
//		go(index + 1, n, m);
//		c[i] = false;
//	}
//}
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	go(0, a, b);
//}

// 변하는 값 : 순서, 들어갈 수 있는 값

#include <iostream>
#include <vector>
using namespace std;

vector<int> number(10, 0);
vector<bool> isUsed(10, false);

void go(int index, int maxNum, int count)
{
	if (index == count)
	{
		for (int i = 0; i < index; i++)
		{
			cout << number[i] << ' ';
		}

		cout << '\n';
		return;
	}

	for (int i = 1; i <= maxNum; i++)
	{
		if (isUsed[i]) continue;

		isUsed[i] = true;
		number[index] = i;
		go(index + 1, maxNum, count);
		isUsed[i] = false;
	}
}

int main()
{
	int a, b;
	cin >> a >> b;

	go(0, a, b);
}