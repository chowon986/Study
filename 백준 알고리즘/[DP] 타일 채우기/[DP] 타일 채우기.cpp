// [DP] 타일 채우기

#include <iostream>
using namespace std;

int D[35];

int main()
{
	int N;
	cin >> N;

	if (N % 2 == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	D[0] = 1;
	D[1] = 0;
	D[2] = 3;
	for (int i = 4; i <= N; i = i + 2)
	{
		D[i] = D[i - 2] * D[2];
		for (int j = i - 4; j >= 0; j = j - 2)
		{
			D[i] = D[i] + (D[j] * 2);
		}
	}

	cout << D[N];
}