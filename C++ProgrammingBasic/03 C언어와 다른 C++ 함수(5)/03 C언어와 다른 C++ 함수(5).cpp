#include <iostream>

// C++ 함수의 특징
// (5) suffix return type
// 후위 반환 타입
// 함수의 변환 타입을 함수의() 뒤쪽에 적는 표기법
// auto 함수명(인자) -> 반환 타입

// 후위 반환 타입
// (1) 복잡한 형태의 함수 템플릿
// template<class T?
// T add(T a, T b)
// {
//     return a+b;
// }
// 
// int main()
// {
// std::cout << add(1, 2.1) << std::endl; //error 두개의 타입이 달라서 모름
// 해결 방법
// template<class T1, class T2>
// decltype(a+b) add(T1 a, T2 b)
// {
//     return a+b;
// }
// int main()
// {
// std::cout << add(1, 2.1) << std::endl; //error 선언되지 않음
// }
// decltype (a + b) add (T1 a, T2 b)
//   1. 이게 먼저       2. 변수 선언 -> 선언 전 사용이니까 오휴
// 이걸 아래와 같이 바꾸면
// auto add(T1 a, T2 b) -> decltype(a + b) // 컴파일 가능 C++11
// auto add(T1 a, t2 b) // 컴파일 가능 C++14부터 지원
// 
//(2) 람다 표현식


int add1(int a, int b)
{
    return a + b;
}

auto add2(int a, int b) -> int
{
    return a + b;
}

int main()
{
    int ret1 = add1(1, 2);
    int ret2 = add2(1, 2);
}
