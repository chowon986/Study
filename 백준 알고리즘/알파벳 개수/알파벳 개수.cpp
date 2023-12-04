// 알파벳 개수.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string temp;
	cin >> temp;

	int alpha[26] = { 0, };

	for (int i : temp)
		++alpha[i - 'a'];

	for (int i : alpha)
		cout << i << ' ';
}