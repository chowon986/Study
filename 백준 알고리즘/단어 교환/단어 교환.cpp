#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> A, B;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		A.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		B.push_back(temp);
	}

	for (int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;

		auto isA = find(A.begin(), A.end(), a);
		auto isB = find(B.begin(), B.end(), b);

		if (isA != A.end() && isB != B.end())
			swap(A[isA - A.begin()], B[isB - B.begin()]);
	}

	for (auto i : A)
		cout << i << ' ';
}