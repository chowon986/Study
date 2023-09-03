// 01 시각

// 내 풀이

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	int h = 0;
//	int m = 0;
//	int s = 0;
//	int count = 0;
//
//	while (h <= n)
//	{
//		++s;
//
//		if (s == 60)
//		{
//			s = 0;
//			m += 1;
//		}
//
//		if (m == 60)
//		{
//			m = 0;
//			h += 1;
//		}
//
//		string temp1 = to_string(s);
//		string temp2 = to_string(m);
//		string temp3 = to_string(h);
//
//		bool isCounted = false;
//		for (int i = 0; i < temp1.size(); i++)
//		{
//			if (temp1[i] == '3' && !isCounted)
//			{
//				++count;
//				isCounted = true;
//			}
//		}
//
//		for (int i = 0; i < temp2.size(); i++)
//		{
//			if (temp2[i] == '3' && !isCounted)
//			{
//				++count;
//				isCounted = true;
//			}
//		}
//
//		for (int i = 0; i < temp3.size(); i++)
//		{
//			if (temp3[i] == '3' && !isCounted)
//			{
//				++count;
//				isCounted = true;
//			}
//		}
//	}
//
//	cout << count;
//}

#include <iostream>
using namespace std;

bool check(int h, int m, int s)
{
	if (h % 10 == 3 || m % 10 == 3 || s % 10 == 3 || m / 10 == 3 || s / 10 == 3) return true;

	return false;
}

int main()
{
	int n;
	cin >> n;

	int count = 0;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				if (check(i, j, k)) ++count;
			}
		}
	}

	cout << count;
}