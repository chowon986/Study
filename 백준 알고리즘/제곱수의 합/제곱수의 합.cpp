#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int N = 0;
	cin >> N;
	vector<int> D(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		D[i] = i; // 모든 수를 1로 채운 경우 -> Max 케이스
		for (int j = 1; j * j <= i; j++)
		{
			D[i] = min(D[i], D[i - j * j] + 1);
		}
	}

	cout << D[N];
}