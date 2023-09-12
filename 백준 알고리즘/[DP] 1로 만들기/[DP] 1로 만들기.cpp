// [DP] 1로 만들기
// 메모리 5928KB, 시간 4ms

#include <iostream>
using namespace std;

int d[1000001];
int main()
{
	int n;
	cin >> n;


	// 점화식 d[6] = d[6/3] + 1 이랑 d[6/2] + 1 이랑 d[6-1] + 1중에 가장 작은 값

	for (int i = 2; i <= n; i++)
	{
		int tempCount = 1e9;
		if (i % 2 == 0)
			tempCount = d[i / 2] + 1;
		if (i % 3 == 0)
			tempCount = min(d[i / 3] + 1, tempCount);
		if (i - 1 >= 1)
			tempCount = min(d[i - 1] + 1, tempCount);

		d[i] = tempCount;
	}

	cout << d[n];
}