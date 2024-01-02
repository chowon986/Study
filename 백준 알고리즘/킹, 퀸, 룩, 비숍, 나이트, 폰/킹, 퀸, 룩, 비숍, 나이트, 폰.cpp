// 킹, 퀸, 룩, 비숍, 나이트, 폰

#include <iostream>
using namespace std;

int main()
{
	int k, q, l, b, n, p;
	int ok = 1;
	int oq = 1;
	int ol = 2;
	int ob = 2;
	int on = 2;
	int op = 8;
	cin >> k >> q >> l >> b >> n >> p;

	cout << ok - k << ' ' << oq - q << ' ' << ol - l << ' ' << ob - b << ' ' << on - n << ' ' << op - p;
}