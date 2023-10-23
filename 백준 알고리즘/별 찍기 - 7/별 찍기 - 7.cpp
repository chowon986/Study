// 별 찍기 - 7.cpp

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int blank = 1;
	int j = 1;
	for (; j < n * 2; j += 2)
	{
		for (int k = blank; k < n; k++) cout << ' ';
		for (int i = 0; i < j; i++) cout << '*';

		cout << '\n';
		++blank;
	}

	j -= 4;

	for (; j > 0; j -= 2)
	{
		for (int k = blank; k > n; k--) cout << ' ';
		for (int i = 0; i < j; i++) cout << '*';

		cout << '\n';
		blank++;
	}
}