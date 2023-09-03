// 03 1이 될 때까지

#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int count = 0;

	while (n != 1)
	{
		++count;
		if (n % k == 0)
			n /= k;
		else
			n -= 1;
	}

	cout << count;
}