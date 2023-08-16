//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int Dest;
//	cin >> Dest;
//
//	vector<int> BrokenKeys;
//
//	int BrokenKeyCount = 1;
//	for (int i = 0; i < BrokenKeyCount; i++)
//	{
//		int Temp;
//		cin >> Temp;
//		BrokenKeys.push_back(Temp);
//	}
//
//	if (Dest == 100)
//	{
//		cout << 0;
//		return 0;
//	}
//
//
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int curChannel = 100;
//
//	int target;
//	cin >> target;
//
//	vector<bool> channels(12, 1);
//
//	int brokenChannelCount;
//	cin >> brokenChannelCount;
//
//	for (int i = 0; i < brokenChannelCount; i++)
//	{
//		int temp;
//		cin >> temp;
//
//		if (temp == '+')
//			channels[10] = 0;
//		else if (temp == '-')
//			channels[11] = 0;
//		else
//			channels[temp] = 0;
//	}
//
//	int moveCount = curChannel > target ? curChannel - target : target - curChannel;
//
//	int min = target;
//	if(min == 0)
//
//	int temp = min;
//
//	while (min > 0 && channels[10] == true)
//	{
//		if (channels[temp % 10] == false)
//		{
//			--min;
//			if (min < 0)
//			{
//				min = -1000000;
//				break;
//			}
//			temp = min;
//		}
//		else
//		{
//			temp /= 10;
//			if(temp == 0)
//			{
//				min = temp;
//				break;
//			}
//		}
//	}
//
//
//	string size = to_string(min);
//	int minLength = size.size();
//
//	int max = target;
//	temp = max;
//
//	while (channels[11] == true && temp < 1000000)
//	{
//		if (channels[temp % 10] == false)
//		{
//			++max;
//			temp = max;
//		}
//		else
//		{
//			temp /= 10;
//			if (temp == 0)
//				break;
//		}
//	}
//
//
//	size = to_string(max);
//	int maxLength = size.size();
//
//	cout << std::min(moveCount, std::min((target - min + minLength), (max - target + maxLength)));
//	return 0;
//}

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