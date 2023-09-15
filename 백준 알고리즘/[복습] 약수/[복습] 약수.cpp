// [복습] 약수

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int maxValue = -1;
	int minValue = 1000001;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		maxValue = max(num, maxValue);
		minValue = min(num, minValue);
	}

	cout << maxValue * minValue;
}