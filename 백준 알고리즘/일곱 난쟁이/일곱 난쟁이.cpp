// 일곱 난쟁이.cpp

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int heights[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		int temp;
		cin >> temp;
		heights[i] = temp;
		sum += temp;
	}

	sort(heights, heights + 9);

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int temp = heights[i] + heights[j];

			if (sum - temp == 100)
			{
				for (int k : heights)
				{
					if (k == heights[i] || k == heights[j]) continue;
					cout << k << '\n';
				}

				return 0;
			}
		}
	}
}