// 05 곱하기 혹은 더하기

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	cin >> a;

	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int temp = a[i] - '0';
		
		if (i == 0)
			sum = temp;
		else if (a[i - 1] == '0') sum += temp;
		else if (temp == 0) sum += temp;
		else sum *= temp;
	}

	cout << sum;
}