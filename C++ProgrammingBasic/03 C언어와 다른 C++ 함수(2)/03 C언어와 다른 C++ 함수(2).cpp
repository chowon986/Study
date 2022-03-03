#include <iostream>

// C++ 함수의 특징
// (2) function overloading
// : 인자의 개수나 인자의 타입이 다르면 "동일한 이름의 함수를 여러 개 만들 수 있다"
// 단, 함수 호출 시 어느 함수를 호출할지 구별할 수 있어야 한다.
// 특징 : 함수 사용자 입장에서는 동일한 함수처럼 생각하게 된다.
// 사용하기 쉬운 일관성 있는 형태의 라이브러리를 구축
// c언어를 제외한 대부분의 최신 언어들이 지원하는 문법


int square(int a)
{
    return a * a;
}

double square(double a)
{
    return a * a;
}

int main()
{
    auto ret1 = square(3);
    auto ret2 = square(3.4);

    std::cout << ret1 << std::endl; // 9
    std::cout << ret2 << std::endl; // 11.56

}

// 주의사항 : 인자의 개수가 달라도 default parameter가 있는 경우는 주의
// void f4(int a) {}
// void f4(int a, int b = 0) {}
// f4(1, 2);
// f4(1); // 만들수는 있으나 ambiauos error

// 함수 반환 타입만 다른 경우는 오버로딩 안됨
// void f3(int a) {}
// char f3(int a) {return 0;} // error

// void f5(char a) {}
// void f5(short a) {}
// f5('a') -> 첫번째 찾아감
// f5(1) -> 둘중 누굴 호출하는지 컴파일러가 판단할 수 없음

// name mangling
// function overloading의 원리
// 컴파일러가 "컴파일 시간에 함수의 이름"을 변경 하는 것
// 컴파일 된 후의 코드에 있는 함수는 모두 이름이 다르다.
// name mangling이라 불리는 현상

// C/C++ 호환성 문제
// 파일별로 각각 컴파일 후, 생성된 오브젝트 파일을 링커가 결합
// extern "C"
// 함수(변수)가 C언어로 작성된 것이라고 C++ 컴파일러에게 알려주는 것
// 헤더에 포함하면 된다.
// 하나의 헤더파일을 C/C++에서 모두 사용할면 "조건부 컴파일"을 해야한다.

/* 
#pragma once

#ifdef __cplusplus
extern "C"
#endif
    int square(int);
    
 #ifdef __cplusplus
 }
 #endif
 */