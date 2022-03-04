#include <iostream>

// C++ 함수의 특징
// (4) inline function
// (일반 함수 호출) 함수 인자를 약속된 장소에 넣고, 함수로 이동
// (인라인 함수 호출) 함수 호출 코드를 "함수의 기계어 코드로 치환" 해 달라


int Add1(int a, int b)
{
    return a + b;
}

inline int Add2(int a, int b)
{
    return a + b; // 이 내용을 main() 의 int ret2 = 여기에 바로 치환
}

int main()
{
    int ret1 = Add1(1, 2);
    int ret2 = Add2(1, 2);

    int(*f)(int, int) = &Add2; 
}

// Linkage

int Add1(int a, int b)
{
    return a + b;
}

inline int Add2(int a, int b) // 링크 에러
{
    return a + b;
}

template<class T> // 링크 에러
T Add3(T a, T b)
{
    return a + b;
}

int main()
{
    Add1(1, 2);
    Add2(1, 2);
    Add3(1, 2);
}

// 컴파일러는 모든 소스 파일을 동시에 컴파일 하지 않고, "파일별로 분리해서 컴파일"한다.
// 링커가 main.cpp와 cpp를 연결해야한다.
// 인라인 치환은 링커가 알 수 없다.
// Add3의 구현을 알 수 없다.
// 인라인 함수와 함수 템플릿은 함수 구현 자체를 헤더파일에 넣어야 한다. -> 문제 해결
