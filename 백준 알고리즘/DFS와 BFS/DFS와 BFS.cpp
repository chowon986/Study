#include <iostream>
using namespace std;

int Sum(int Num)
{
	if (Num == 0)
		return 0;

	return Sum(Num - 1) + Num;
}

int main()
{
	cout << Sum(100);
}