// #include <cstdio> // C
#include <iostream> //C++
#include <iomanip> // setw 사용할 때

int main()
{
	int n = 10;
	double d = 3.4;

	// printf("%d, %f\n", n, d); // C
	std::cout << n << ", " << d << std::endl; // C++

	// scanf("%d", &n); // 주소(&n)를 전달 C
	// std::cin >> n; // 주소가 아닌 "n"로 전달 C++


	//io manipulator 조정자(조작자) 함수
	//입출력시의 다양한 출력(입력) 형태를 저장하는 것
	//<iostream>, <iomanip> 등
	std::cout << n << std::endl;
	std::cout << std::hex << std::endl;
	std::cout << std::dec << std::endl;
	std::cout << std::setw(10) << std::setfill('#') << n << std::endl;
	// 10칸인데, 빈칸은 #으로 채워주세요
	std::cout << std::setw(10) << std::setfill('#') << std::left << n << std::endl;
	// 10칸인데, 빈칸은 #으로 채워주시고, 왼쪽부터 써주세요
	std::cout << std::setw(10) << std::setfill('#') << std::right << n << std::endl;
}

// std::dec     | 변수값을 10진수로 출력
// std::hex     | 변수값을 16진수로 출력
// std::setw    | 문자열 출력 시 개수 지정
// std::setfill | 공백을 채울 문자 지정
// std::left    | 왼쪽 정렬