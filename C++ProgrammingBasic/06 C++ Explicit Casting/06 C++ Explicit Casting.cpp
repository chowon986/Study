#include <iostream>

int main()
{
    // C언어 캐스팅
    //int* p = (int*)malloc(sizeof(int)*10);
    // 문제점
    // (1) 논리적으로 위험한 캐스팅 코드도 대부분 허용
    // -> 위험한 캐스팅이 "개발자의 실수 인지 의도된 것인지 구분하기 어렵다"

    // void* -> 다른 타임(int*) 로 캐스팅
    // -> 위험 하기 보다는 프로그램 개발 시 "반드시 필요한 캐스팅"

    // int* -> 다른 타입(double*) 로 캐스팅
    // -> int 주소를 double 변수에 담는 것은 위험하다.
    // -> 개발자가 의도한 캐스팅일까? 실수 일까?

    // 상수 변수 주소를 비 상수를 가리키는 포인터로 캐스팅
    // const int c = 10;
    // int* p3 = &c; // error
    // int* p3 = (int*)&c; // ok
    // *p3 = 20; // 값을 바꾸지 않겠다고 해놓고 21번 줄과 같이 캐스팅 하며
    // 22번 줄이 error 나지 않음


    // C++언어 캐스팅
    int* p1 = static_cast<int*>(malloc(sizeof(int) * 10));
    // (1) static_cast
    // 논리적으로 맞고, 반드시 필요한 경우의 캐스팅만 허용
    // 대부분의 프로그램은 이 캐스팅을 사용해야 한다.
    // void -> 다른 타입 포인터
    // primitive type 가느이 값 캐스팅
    // 상속 관계 타입 간의 캐스팅
    // 사용자 정의 변환 연산자나 변환 생성자가 있는 경우

    int* c1 = static_cast<int*>(malloc(100)); // void -> int

    int n = 10;
//    double* c2 = static_cast<double*>(&n); // error
    
    const int n2 = 10;
    int* p3 = (int*)&n2; // ok
//    int* p3 = static_cast<int*>(&n2); // error

    // -> static_cast 가 허용하지 않는 캐스팅의 경우
    // 해당 기능을 수행하는 " 다른 캐스팅 방법 사용 "
    
     
    // (2) reinterpret_cast
    // -> 메모리의 재해석
    // -> 메모리의 해석 방식을 변경하는 캐스팅
    // 1. 서로 다른 타입의 주소(참조) 캐스팅
    int k = 10;
//    char* k1 = static_cast<char*>(&n); // error
    char* k2 = reinterpret_cast<char*>(&n); // ok

//    char& r1 = static_cast<char&>(n); // error
    char& r2 = reinterpret_cast<char&>(n); // ok

    // 2. 정수 <-> 주소 사이의 캐스팅
//     int* p3 = static_cast<int*>(1000); // error
    int* p4 = reinterpret_cast<int*>(1000); // ok

//    double d = reinterpret_cast<double>(3); // error -> static 사용

    // (3) const_cast
    // -> 객체(변수)의 상수성을 제거하는 캐스팅
    const int c = 10;
//   int* p1 = static_cast<int*>(&c); // error
//   int* p2 = reinterpret_cast<int*>(&c); // error
    int* p3 = const_cast<int*>(&c); // ok 
    // 이 주소를 어느 공간에 보관하는 정도만 써야지 아래와 같이는 쓰지 마라
    // *p3 = 20;

    // (4) dynamic_cast
    // -> 상속 관계에서 안전한 down casting : 상속 공부 후 다루기
    // - - -

    const int d = 10;
    char* d1 = (char*)&d;

    // 위 코드와 동일하게 동작하는 캐스팅 코드를 C++로 작성해 보세요
    // char* d2 = reinterpret_cast<char*>(&c); // error. const 제거 안 됨
    // char* d2 = const_cast<char*>(&c);       // error. int* => char* 안 됨
    char* d2 = reinterpret_cast<char*>(const_cast<int*>(&c));
    // 상수성을 제거한 후에 코드를 바꾸겠다.

    char* d3 = const_cast<char*>(reinterpret_cast<const char*>(&c));
    // 코드를 const char*로 바꾸고 나서 상수성을 제거 하겠다.
    // 위 코드와 동일
}

