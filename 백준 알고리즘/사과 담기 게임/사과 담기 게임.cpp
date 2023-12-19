// 사과 담기 게임

#include <iostream>
using namespace std;

int main()
{
	int n, m, j;
	cin >> n >> m >> j;

	int startIdx = 1;
	int endIdx = m;
	int answer = 0;

	for (int i = 0; i < j; i++)
	{
		int temp;
		cin >> temp;
		int count = 0;

		while (true)
		{
			if (temp >= startIdx && temp <= endIdx)
				break;
			
			if (temp > endIdx && endIdx < n)
			{
				++startIdx;
				++endIdx;
				++count;
			}
			else if (temp < startIdx && startIdx > 1)
			{
				--startIdx;
				--endIdx;
				++count;
			}
		}

		answer += count;
	}

	cout << answer;
}