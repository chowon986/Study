// [복습] 일곱 난쟁이

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> talls(9);

	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		int temp;
		cin >> temp;
		talls[i] = temp;
		sum += temp;
	}

	sort(talls.begin(), talls.end());

	int temp;
	for (int i = 0; i < 9; i++)
	{
		temp = sum;
		for (int j = 0; j < 9; j++)
		{
			if (i == j) continue;

			if (temp - (talls[i] + talls[j]) == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j) continue;
					cout << talls[k] << '\n';
				}
				return 0;
			}
		}
	}
}