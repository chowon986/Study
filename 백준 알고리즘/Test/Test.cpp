#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
    }

    ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor" << std::endl;
        dynamicData = new int[5];  // 동적으로 메모리 할당
    }

    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
        delete[] dynamicData;  // 동적으로 할당한 메모리 해제
    }

private:
    int* dynamicData;
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // 문제가 발생하는 부분

    return 0;
}