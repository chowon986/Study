// [복습] 1

#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int i = 0;
		int sum = 0;
		for (int i = 0; ; i++)
		{
			sum = 10 * sum + 1;
			sum %= n;

			if (sum == 0)
			{
				cout << i + 1 << '\n';
				break;
			}
		}
	}
}