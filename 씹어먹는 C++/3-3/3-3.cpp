// 3-3.cpp : : malloc, free 그리고 new, delete

// new로 배열 할당하기
#include <iostream>
using namespace std;

int main()
{
	int arr_size;
	cout << "array size : ";
	cin >> arr_size;

	int* list = new int[arr_size];

	for (int i = 0; i < arr_size; i++)
	{
		cin >> list[i];
	}

	for (int i = 0; i < arr_size; i++)
	{
		cout << i << "th element of list : " << list[i] << '\n';
	}

	delete[] list;
}