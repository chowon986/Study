//#include <iostream>
//using namespace std;
//
//bool broken[10];
//
//int possible(int c)
//{
//	if (c == 0)
//	{
//		if (broken[0]) return 0;
//		else return 1;
//	}
//
//	int len = 0;
//
//	while (c > 0)
//	{
//		if (broken[c % 10]) return 0;
//		len += 1;
//		c /= 10;
//	}
//
//	return len;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	int m;
//	cin >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int x;
//		cin >> x;
//		broken[x] = true;
//	}
//
//	int ans = n - 100;
//	if (ans < 0) ans = -ans;
//
//	for (int i = 0; i <= 1000000; i++)
//	{
//		int c = i;
//		int len = possible(c);
//		if (len > 0)
//		{
//			int press = c - n;
//			if (press < 0)
//				press = -press;
//
//			if (ans > len + press)
//				ans = len + press;
//		}
//	}
//
//	cout << ans;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int target;
	cin >> target;

	int brokenCount;
	cin >> brokenCount;

	vector<bool> isBrokenButton(10, false);

	for (int i = 0; i < brokenCount; i++)
	{
		int temp;
		cin >> temp;
		isBrokenButton[temp] = true;
	}

	int curChannel = 100;
	int minButton = target;
	int temp = minButton;

	while (temp > 0)
	{
		if (isBrokenButton[temp % 10] == false)		temp /= 10;
		else
		{
			--minButton;
			temp = minButton;
		}
	}

	if (minButton == 0)
	{
		if (isBrokenButton[0]) minButton = -1000000;
		else minButton = 0;
	}

	int minPressCount = to_string(minButton).size();
	minPressCount += (target - minButton);

	int maxButton = target;
	temp = maxButton;

	while (temp >= 0 && temp < 1000000)
	{
		if (isBrokenButton[temp % 10] == false)
		{
			temp /= 10;
			if (temp == 0)
				break;
		}
		else
		{
			++maxButton;
			temp = maxButton;
		}
	}

	int maxPressCount = to_string(maxButton).size();
	maxPressCount += (maxButton - target);

	int pressCount = target > curChannel ? target - curChannel : curChannel - target;

	cout << min(pressCount, min(minPressCount, maxPressCount));
}