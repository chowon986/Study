// static member data #2

#include <iostream>

// static member data에 접근하는 방법
// c1.count (가능은하나 main()만 보면 static 멤버인지 아닌지 구분이 되지 않는다)
// Car::count 이 방식을 권장
// private영역에 있는 경우 static 멤버 함수로 접근

int main()
{
    std::cout << "Hello World!\n";
}

// 클래스를 선언과 구현으로 분리할 경우
// static 멤버 변수의 외부 선언은 구현파일(.cpp)에 있어야 한다.
// 다음의 경우에는 외부 선언 없이 클래스 내부에서 초기화 가능
// (1) static const
// (2) static constexpr
// (3) inline variable
// 얘네들은 static const int data1 = 3; 이런식으로 바로 초기화 가능하다.

