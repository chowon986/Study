// 가상함수

#include <iostream>

class Animal
{
    int age;
public:
    virtual void cry()
    {
        std::cout << "Animal cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void cry()
    {
        std::cout << "Dog cry" << std::endl;
    }
};

int main()
{
    Animal a;
    a.cry();

    Dog d;
    d.cry();

    Animal* p = &d;
    p->cry(); // 애니멀이 호출되지 않을까?
}

// 함수 바인딩
// 어느 함수와 연결할지를 결정하는 과정
// (1) static binding(early binding)
// // 컴파일러가 컴파일 시간에 함수 호출을 결정
// 컴파일러는 아래 식에서 p가 실제로 어느 객체를 가리키는지는
// 컴파일 시간에 알 수 없다.
// -> 이 경우 animal의 cry로 간다.


// (2) dynamic binding(late binding)
// 컴파일 시간에는 p가 가리키는 곳을 조사하는 기계어를 생성
// 실행 시간에 p가 가리키는 곳을 조사한 후 실제 메모리에 있는
// 객체에 따라 함수 호출 결정
// dog 객체가 있었다면 dog cry 호출

class Animal
{
    int age;
public:
    virtual void cry()
    {
        std::cout << "Animal cry" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void cry()
    {
        std::cout << "Dog cry" << std::endl;
    }
};

int main()
{
    Animal a;
    Dog d;
    Animal* p = &d;
    p->cry(); // Animal cry가 호출된다.

    if (/*사용자입력값==1*/)
    {
        p = &a;
        p->cry();
    }
}

// 가상함수는 함수 이름앞에 virtual을 붙이면 된다.
// virtual이 안붙으면 static / 붙으면 dynamic이 발동
