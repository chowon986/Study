/*  이름, 주소, 나이를 입력받아 다시 출력하는 프로그램을 작성하라.
    (황기태, 서울시 안녕구 사랑동 해피아파트, 21세)  */

#include <iostream>
using namespace std;

int main()
{
    char name[100];
    char address[100];
    int age;

    cout << "이름은?";
    cin.getline(name, 100, '\n');
    cout << "주소는?";
    cin.getline(address, 100, '\n');
    cout << "나이는?";
    cin >> age;
    cout << name << ", " << address << ", " << age << "세";
}
