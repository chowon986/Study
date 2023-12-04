// 트럭 주차.cpp 

#include <iostream>
using namespace std;

int main()
{
	int money[4] = { 0, };
	for (int i = 1; i <= 3; i++)
	{
		int temp;
		cin >> temp;
		money[i] = temp;
	}

	int time[101] = { 0, };

	int minvalue = 101;
	int maxValue = 0;

	for (int i = 0; i < 3; i++)
	{
		int tempA, tempB;
		cin >> tempA >> tempB;

		minvalue = min(minvalue, tempA);
		maxValue = max(maxValue, tempB);

		for (int j = tempA; j < tempB; j++)
			++time[j];
	}

	int sum = 0;
	for (int i = minvalue; i <= maxValue; i++)
	{
		sum += money[time[i]] * time[i];
	}

	cout << sum;
}