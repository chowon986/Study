// [복습] 최대공약수와 최소공배수

#include <iostream>
using namespace std;

int gcd(int n, int m)
{
	if (n < m) swap(n, m);
	
	int temp = n % m;
	n = m;
	m = temp;

	if (temp == 0) return n;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int result = gcd(n, m);
	cout << result <<'\n';
	cout << (n / result) * (m / result) * result;
}