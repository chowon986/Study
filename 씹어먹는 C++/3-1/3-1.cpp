// 3-1.cpp : malloc, free 그리고 new, delete

// new와 delete의 사용

#include <iostream>
using namespace std;

int main()
{
	int* p = new int;
	*p = 5;

	cout << *p << '\n';

	delete p;

	return 0;
}