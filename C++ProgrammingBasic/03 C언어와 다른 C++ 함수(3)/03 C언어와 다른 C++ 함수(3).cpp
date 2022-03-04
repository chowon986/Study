#include <iostream>

// C++ 함수의 특징
// (3) function template
// 구현이 동일(유사)한 함수가 여러 개 필요하면
// "함수를 만들지 말고 함수를 생성하는 틀(템플릿)"을 만들자
// template<typename T>
// 함수 템플릿을 만들고 사용하지 않으면 실제 함수는 생성되지 않는다.

// 틀 만들기
template<typename T>
T square(T a)
{
    return a * a;
}
int main()
{
    square<int>(3);
    square(3.8f); // 이렇게 하면 컴파일러가 3.8f를 보고 자료형을 추론해서 넣어준다.
    square<double>(3.4);

    char c = 3;
    short s = 3;
    int n = 3;
    square(c);
    square(s);
    square(n);
    // 코드 폭발(Code Bloat)
    // 템플릿이 너무 많은 타입에 대해 인스턴스화 되어서 코드 메모리가 증가하는 현상
    // square<int>(c);
    // square<int>(s); 이런식으로도 사용 가능
}

// 컴파일 한 후의 코드
/*
int square(int a)
{
return a * a;

double square(double a)
{
return a * a;
*/

// 함수 템플릿을 만드는 방법
/*  template<typename T> -> 이 부분을 class로도 사용 가능 template<class T>이런 식으로
    T square(T a)
    {
        return a * a;
    }
 */

/* 함수와 함수 템플릿
    template<class T>
    T square(T a)
    {
        return a * a;
    }

    int main()
    {
    square<int>(3);
    square(3); // square는 함수가 아님 -> 틀은 주소가 없다.
    printf("%p\n", &square); // error
    printf("%p\n", &square<int>); // ok -> 이 틀에 int를 넣은것의 주소

    square는 함수가 아니라 함수 템플릿이다. square의 주소는 구할 수 없다.
    square<타입> 함수(함수이름). 함수의 주소는 구할 수 있다.
*/