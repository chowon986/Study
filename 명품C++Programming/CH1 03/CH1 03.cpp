// 1부터 10까지 더하여 결과를 화면에 출력하라
// 힌트 : std::cout << "결과는 " << 55 << "입니다";
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 1; i < 11; i++)
    {
        sum += i;
    }
    std::cout << "결과는 " << sum << "입니다";
}
