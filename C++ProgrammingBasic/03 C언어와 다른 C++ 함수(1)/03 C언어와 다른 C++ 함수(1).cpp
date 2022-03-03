#include <iostream>

void foo(int a, int b = 0, int c = 0)
{
    std::cout << a << ", " << b << ", " << c << std::endl;

}

int main()
{
    // C++ 함수의 특징
    // (1) default parameter
    // : 함수 호출 시 인자를 전달하지 않으면, 미리 지정된 인자 값을 사용할 수 있다.
    foo(1, 2, 3); // 1, 2, 3
    foo(1, 2); // 1, 2, 0
    foo(1); // 1, 0, 0
}
// 주의사항 : (1) 함수의 마지막 인자부터 차례대로 디폴트 값을 지정해야 한다.
//           (2) 함수를 선언과 구현으로 분리할 때는 "함수 선언부에만 디폴트 값을 표기해야한다"

// 주의사항 (1)
void f1(int a = 0, int b = 0, int c = 0)
{

} //OK
void f2(int a, int b = 0, int c = 0)
{

} // OK
//void f3(int a = 0, int b, int c = 0) {} // error
//void f4(int a = 0, int b = 0, int c) {} error

// 주의사항 (2)
void foo1(int a, int b = 0, int c = 0);

// void foo(int a, int b = 0, int c = 0) // 기본 인수 재정의
// {

// }

void foo1(int a, int b, int c)
{

} // ok 

//디폴트 값이 있다는걸 모를 수 있으므로 주석으로 표기해도 괜찮다.

void foo2(int a, int b /* = 0 */, int c /* = 0*/)
{

} // ok 

// default parameter의 원리
// 컴파일러가 컴파일 시에 "함수 호출하는 코드의 함수 인자에 디폴트 값을 채워 주는 것"
// void foo(int a, int b = 0, int c = 0);
// int main()
// {
//      foo(1,0,0);
//      foo(1); 이렇게 넣으면 컴파일러가 foo(1, 0, 0)으로 채움
// }
