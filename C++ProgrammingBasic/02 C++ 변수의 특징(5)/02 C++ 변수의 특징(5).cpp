#include <iostream>
// #include <cstring> -> string.h의 c++버전
#include <string> // -> std::string을 사용하기 위한 헤더

int main()
{
    char s1[] = "abcd";
    char s2[5];

    //s2 = s1; // error
    strcpy_s(s2, s1);

    // if (s2 == s1)
    if(strcmp(s2,s1) == 0)
    {
        std::cout << "same" << std::endl;
    }
    else
    {
        std::cout << "not same" << std::endl;
    }

    // std::string
    // C++ 표준 라이브러리인 STL이 제공하는 문자열 타입
    // class 문법으로 만들어진 "사용자 정의 타입"
    // 문자열 변수를 정수형 변수와 유사하게 사용 가능(+, ==, = 등의 연산자 사용 가능)

    std::string x1 = "abcd";
    std::string x2;

    x2 = x1;

    if (x2 == x1)
    {
        std::cout << "same" << std::endl;
    }
    else
    {
        std::cout << "not same" << std::endl;
    }
    std::string x3 = x1 + x2;
    std::cout << x3 << std::endl;

    bool b = true; // false, 0, 1
    long long n = 10; // c++11 64bit 정수
    int n1 = 0b1000'0000; // 2진수 표기법
    int n2 = 1'000'000; // ' = digit separator

    int* k1 = 0;
    int* k2 = nullptr;
}
