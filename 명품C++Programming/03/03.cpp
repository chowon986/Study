// 실습문제 3
// 1에서 10까지 더하여 결과를 화면에 출력해라

#include <iostream>

int main()
{
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		sum += 1 + i;
	}
	std::cout << "결과는 " << sum << " 입니다.";
}
