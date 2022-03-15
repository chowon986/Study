#include <iostream>

class Vector
{
public:
    Vector(int size) 
    {

    }
};

void foo(Vector V)
{

}

class Object
{
};

void foo(Object obj)
{

}

int main()
{
    Vector v1(10);      // 직접 초기화
    Vector v2 = 10;     // 복사 초기화
    Vector v3{ 10 };    // 직접 초기화
    Vector v4 = { 10 }; // 복사 초기화

    // 인자가 1개인 생성자는 변환의 용도로 사용될 수 있다.
    v1 = 20; // v1 = Vector(20); // 변환 생성자
    foo(v1); // ok
    foo(10); // foo()가 Vector를 받는데 10을 넣어도 에러가 나지 않는다.
             // Vector v = 10; 복사 초기화가 된다. -> 일부러 하기 보다는 보통 다른 함수에 넣을 값을 실수로 한다.
             // 아래 방법으로 예방 가능


    Object o1;
    Object o2{};
    Object o3 = {};
}
/* Vector class 안에 아래와 같이 넣으면
explicit Vector(int size) // explicit는 직접 초기화는 가능한데 복사 초기화는 불가하다.
                          // 암시적 변환의 용도로 사용될 수 없다.
{

}
*/

// STL과 explicit 생성자
// string = explicit 아님
// vector = explicit 임

// vector는 v3 = 10; 은 에러지만 v4 = {10}은 에러나지 않는다.
// v4는 list (explicit 아님) 때문에

// explicit는 인자의 개수가 없거나 여러 개인 경우에도 붙일 수 있다.


// explicit(true) 라고하면 explicit다
// explicit(false) 라고하면 explicit다.
// false라고 적을거면 두번째를 안해도 되지 않나요?
// 주로 템플릿에서 씁니다.
template<typename T>
explicit(std::is_integral_v<T>) Object(T arg) {}
// 정수형 배열이면 true, 그렇지 않으면 false로 해라 이런 식으루