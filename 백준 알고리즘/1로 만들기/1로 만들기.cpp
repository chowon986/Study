// 1로 만들기

// 시간 초과
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int minValue = 1000000;
//
//void go(int x, int count, int curNum)
//{
//	if (curNum > x)
//		return;
//
//	if (curNum == x)
//	{
//		minValue = min(count, minValue);
//		return;
//	}
//
//	for (int i = 1; i <= 3; i++)
//	{
//		if (i == 1) 
//			go(x, count + 1, curNum + 1);
//		else
//			go(x, count + 1, curNum * i);		
//	}
//}
//
//int main()
//{
//	int x;
//	cin >> x;
//
//	go(x, 0, 1);
//	cout << minValue;
//}

#include <iostream>
#include <vector>
using namespace std;

vector<int> d(1000001);
int go(int n)
{
	if (n == 1)
		return 0;

	if (d[n] > 0)
		return d[n];

	d[n] = go(n - 1) + 1;
	if (n % 2 == 0)
	{
		int temp = go(n / 2) + 1;
		if (d[n] > temp) d[n] = temp;

	}
	if (n % 3 == 0)
	{
		int temp = go(n / 3) + 1;
		if (d[n] > temp) d[n] = temp;
	}

	return d[n];
}

int main()
{
	int n;
	cin >> n;
	cout << go(n);
}