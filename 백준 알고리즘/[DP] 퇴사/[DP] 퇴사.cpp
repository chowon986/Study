// [DP] 퇴사

#include <iostream>
#include <vector>
using namespace std;

vector<int> day;
vector<int> money;

int sum = 0;

void go(int curDay, int curSum, int endDay, int i)
{
	if (curDay == endDay)
	{
		sum = max(sum, curSum);
		return;
	}

	if (curDay > endDay) return;

	go(curDay + day[i], curSum + money[i], endDay, i + day[i]);
	go(curDay + 1, curSum, endDay, i + 1);
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int n, m;
		cin >> n >> m;
		day.push_back(n);
		money.push_back(m);
	}

	go(0, 0, tc, 0);

	cout << sum;
}