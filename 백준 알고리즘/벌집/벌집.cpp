// 벌집.cpp

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int temp = 1;
	int idx = 1;
	while (temp < n)
		temp += (6 * idx++);

	cout << idx;
}