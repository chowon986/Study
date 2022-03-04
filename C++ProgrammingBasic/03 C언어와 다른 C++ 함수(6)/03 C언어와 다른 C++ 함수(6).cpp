#include <iostream>

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

// (1) double gcd(double a, double b); // 구현이 없다. 선언만
/*(2)*/double gcd(double a, double b) = delete; // 함수 삭제 

int main()
{
    gcd(10, 4);
    // gcd(3.3, 4.4); // (1)컴파일러는 구현은 못 찾지만 링크에게 넘김. 링크야 너가 찾아서 연결해줘
                     // 링크 에러 발생
                     //  (2)함수 삭제를 하면 컴파일에서 에러 발생
                     // 삭제된 함수를 참조하려고 합니다.
}

