// 숨바꼭질6.cpp 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned int> v;

unsigned int gcd(unsigned int a, unsigned int b)
{
	if (b == 0) return a;

	return gcd(b, a % b);
}

int main()
{
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(abs(temp - s));
	}

	if (n == 1)
	{
		cout << v[0];
		return 0;
	}

	sort(v.begin(), v.end());

	unsigned int curNum = gcd(v[0], v[1]);

	for (int i = 2; i < n; i++)
		curNum = gcd(curNum, v[i]);

	cout << curNum;
}