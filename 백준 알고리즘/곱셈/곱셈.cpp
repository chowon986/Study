#include <iostream>
using namespace std;

int Power(int base, int exponent, int divisor)
{
	if (exponent == 1)
		return base % divisor;

	int num = Power(base, exponent / 2, divisor) % divisor;
	num = (long long)num * num % divisor;

	if (exponent % 2 == 0)
		return num;
	else
		return (long long)num * base % divisor;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	cout << Power(a, b, c) << '\n';
}