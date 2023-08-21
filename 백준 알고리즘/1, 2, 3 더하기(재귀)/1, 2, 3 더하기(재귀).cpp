// 1, 2, 3 더하기(재귀)

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int sum = 0;
//
//int go(int sum, int goal)
//{
//	if (sum > goal) return 0;
//	if (sum == goal) return 1;
//	int now = 0;
//	for (int i = 1; i <= 3; i++)
//	{
//		now += go(sum + i, goal);
//	}
//
//	return now;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	cout << go(0, n);
//}

#include <iostream>
using namespace std;

int go(int sum, int goal)
{
    if (sum > goal) return 0;
    if (sum == goal) return 1;

    int temp = 0;
    for (int i = 1; i <= 3; i++)
    {
        temp += go(sum + i, goal);
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;

    go(0, n);
}