// 00 거스름돈

#include <iostream>
using namespace std;

int change[4] = { 500, 100, 50, 10 };

int main()
{
	int n;
	cin >> n;

	int ans = 0;
	int arrayLength = sizeof(change) / sizeof(int);

	for (int i = 0; i < arrayLength; i++)
	{
		ans += n / change[i];
		n %= change[i];
	}

	cout << ans;
}