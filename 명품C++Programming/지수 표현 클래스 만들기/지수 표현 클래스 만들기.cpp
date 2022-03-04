/*  실수의 지수 표현을 클래스 Exp로 작성하라.
    클래스 Exp를 Exp.h 파일과 Exp.cpp 파일로 분리하여 작성하라. */

#include <iostream>
using namespace std;
#include "Exp.h"

int main()
{
    Exp a(3, 2);
    Exp b(9);
    Exp c;

    cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;
    cout << "a의 베이스 " << a.getBase() << ',' << "지수 " << a.getExp() << endl;

    if (a.equals(c))
    {
        cout << "same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }
}
