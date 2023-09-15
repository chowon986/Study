// [복습] 날짜 계산

#include <iostream>
using namespace std;

int main()
{
	int maxE = 16;
	int maxS = 29;
	int maxM = 20;

	int curE, curS, curM;
	curE = curS = curM = 1;

	int tarE, tarS, tarM;
	cin >> tarE >> tarS >>tarM;

	int count = 1;

	while (tarE != curE || tarS != curS || tarM != curM)
	{
		++count;
		if((++curE %= maxE) == 0) curE = 1;
		if((++curS %= maxS) == 0) curS = 1;
		if((++curM %= maxM) == 0) curM = 1;
	}

	cout << count;
}