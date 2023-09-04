// 02 부품 찾기

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<int> mine;
//	vector<int> order;
//
//	for (int i = 0; i < n; i++)
//	{
//		int temp;
//		cin >> temp;
//
//		mine.push_back(temp);
//	}
//
//	int m;
//	cin >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int temp;
//		cin >> temp;
//
//		order.push_back(temp);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		bool ok = false;
//		for (int j = 0; j < n; j++)
//		{
//			if (order[i] == mine[j])
//			{
//				cout << "yes" << ' ';
//				ok = true;
//				break;
//			}
//		}
//
//		if (ok == false)
//			cout << "no" << ' ';
//	}
//}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> mine(1000001, 0);
	vector<int> order;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		++mine[temp];
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		if (mine[temp] > 0)
			cout << "yes" << ' ';
		else
			cout << "no" << ' ';
	}
}