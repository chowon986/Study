// 이상한 곱셈

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	if (A == "0" || B == "0")
	{
		cout << 0;
		return 0;
	}

	vector<int> vA, vB;

	for (int i = 0; i < A.size(); i++)
	{
		vA.push_back(A[i] - '0');
	}

	for (int i = 0; i < B.size(); i++)
	{
		vB.push_back(B[i] - '0');
	}

	long long sum = 0;
	for (int i = 0; i < vA.size(); i++)
	{
		for (int j = 0; j < vB.size(); j++)
		{
			sum += vA[i] * vB[j];
		}
	}

	cout << sum;
}