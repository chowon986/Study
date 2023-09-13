// [DP] 가장 긴 증가하는 부분 수열 4

#include <iostream>
#include <vector>
using namespace std;

vector<int> b;
vector<int> prevIdx;
vector<int> a;
int maxIdx = -1;
int maxValue = -1;

void printValue(int curIdx)
{
	if (maxIdx == -1)
		return;

	maxIdx = prevIdx[curIdx];
	printValue(maxIdx);

	cout << b[curIdx] << ' ';
}

int main()
{
	int n;
	cin >> n;

	b.resize(n);
	prevIdx.resize(n, -1);
	a.resize(n, 1);
	
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		b[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (b[i] > b[j])
			{
				if (a[i] < a[j] + 1)
				{
					a[i] = a[j] + 1;
					prevIdx[i] = j;
				}
			}
		}

		if (maxValue < a[i])
		{
			maxIdx = i;
			maxValue = a[i];
		}
	}

	cout << maxValue << '\n';

	printValue(maxIdx);
}