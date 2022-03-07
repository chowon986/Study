// 다음과 같이 출력하는 C++ 프로그램을 작성하라
// *
// **
// ***
// ****

#include <iostream>

int main()
{
    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout << '\n';
    }

}

