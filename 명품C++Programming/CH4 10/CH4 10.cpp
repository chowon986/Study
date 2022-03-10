// 아래와 같이 출력되도록 Person과 Family 클래스, main()를 완성하라
// Simpson 가족은 다음과 같이 3명입니다.
// Mr. Simpson      Mrs. Simpson        Bart Simpson

#include <iostream>
#include <string>
using namespace std;

class Person
{
    string name;
public:
    Person()
    {

    }

    Person(string name)
    {
        this->name = name;
    }

    string getName()
    {
       cout << name << '\t';
       return name;
    }
    
    void setName(string name)
    {
        this->name = name;
    }
};

class Family
{
    Person* p;
    int size;
public:
    Family(string name, int size)
    {
        p = new Person[3];
    }

    void show()
    {
        for (int i = 0; i < 3; i++)
        {
            p[i].getName();
        }
    }

    void setName(int num, string name)
    {
        p[num] = name;
    }

    ~Family()
    {
        delete[] p;
    }
};
int main()
{
    Family* simpson = new Family("Simpson", 3);
    simpson->setName(0, "Mr. Simpson");
    simpson->setName(1, "Mr. Simpson");
    simpson->setName(2, "Bart. Simpson");
    cout << "Simpson가족은 다음과 같이 3명 입니다." << endl;
    simpson->show();
    delete simpson;
}
