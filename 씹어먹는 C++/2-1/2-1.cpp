// 2-1.cpp : 참조자, 레퍼런스의 도입

#include <iostream>

int ChangeValue(int* p)
{
	*p = 3;

	return 0;
}

int ChangeValueWithReference(int& p)
{
	p = 3;

	return 0;
}

int main()
{
	int number = 5;

	std::cout << number << std::endl; // 5
	ChangeValue(&number);
	std::cout << number << std::endl; // 3

	int a = 3;
	int& anotherA = a; // &는 선언과 동시에 초기화 필요 (레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야 함)

	anotherA = 5;	   // 중간에 가리키고 있는 대상 변경 불가 (레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없음)
					   // 이 의미는 int a = 5와 같음

	// 상수 리터럴을 참조하는 것은 불가 (단, 앞에 const를 붙이면 가능) 
	// int& p = 5; (X)
	const int& p = 5;



	std::cout << "a : " << a << std::endl;				 // 5
	std::cout << "anotherA : " << anotherA << std::endl; // 5

	// 레퍼런스는 메모리 상에 존재하지 않을수도 있음 (포인터는 당연히 메모리를 차지함)
	// anotherA를 위한 메모리 상에 공간을 할당할 필요가 없음
	// anotherA가 쓰이는 자리는 모두 a로 바꿔치기 하면 됨
	// 단, 항상 존재하지 않는 것은 아님

	int originNumber = 5;
	std::cout << originNumber << std::endl;
	ChangeValueWithReference(originNumber); // 포인터와 달리 원본 그대로의 형태로 함수에 넣어주면 됨
	std::cout << originNumber << std::endl;

	// 포인터와 달리 배열의 레퍼런스의 경우 참조하기 위해선 반드시 배열의 크기를 명시해야 함
	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	int(&ref2)[3] = arr;
}

// 문제 1
// 레퍼런스가 메모리 상에 반드시 존재해야 하는 경우는?
// 함수 인자로 레퍼런스를 받는 경우