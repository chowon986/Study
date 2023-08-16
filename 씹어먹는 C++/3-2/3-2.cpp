// 3-2.cpp : malloc, free 그리고 new, delete

// Heap이 아닌 공간을 해제하면?
#include <iostream>

int main()
{
	int a = 5;

	delete &a;
}