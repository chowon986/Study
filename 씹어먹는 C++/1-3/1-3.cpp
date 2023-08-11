// 1-3.cpp : C++은 C의 친구 - C와 공통점

#include <iostream>

int main()
{
	// 변수 정의
	// 이름 규칙
	// (1) 변수 이름의 맨 앞부분에 숫자가 오면 안 됨

	// int 3match; (X)
	int match3; // (O)

	// (2) 작성 방법
	int number_of_people; // (O)
	int numberOfPeople;	  // (O)

	int NumberOf_People;  // (권장하지 않음)

	// 배열
	int arr[10];
	int* parr = arr;

	int i;
	int* pi = &i;

	// 반복문

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
	}

	int sum = 0;
	for (int j = 0; j < 10; j++) sum += j;

	std::cout << "합은 : " << sum << std::endl;

	int k = 1;
	while (k <= 10)
	{
		k++;
	}

	std::cout << "현재 k는 " << k << std::endl;

	// if문
	int luckyNumber = 3;
	std::cout << "내 비밀 수를 맞추어 보세요" << std::endl;

	int userInput;

	while (1)
	{
		std::cout << "입력 : ";
		std::cin >> userInput;

		if (luckyNumber == userInput)
		{
			std::cout << "맞추셨습니다." << std::endl;
			break;
		}
		else
			std::cout << "다시 생각해보세요" << std::endl;
	}
	
	// switch문

	int userInput2;

	std::cout << "저의 정보를 표시해줍니다" << std::endl;
	std::cout << "1. 이름 " << std::endl;
	std::cout << "2. 나이 " << std::endl;
	std::cout << "3. 성별 " << std::endl;

	std::cin >> userInput2;

	switch (userInput2)
	{
	case 1:
		std::cout << "Psi" << std::endl;
		break;
		
	case 2:
		std::cout << "99살" << std::endl;
		break;

	case 3:
		std::cout << "남자" << std::endl;
		break;

	default:
		std::cout << "궁금한게 없군요" << std::endl;
		break;
	}
}