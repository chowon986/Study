// 문제 5번을 참고하여 생성잘ㄹ 이용하여 짝수 홀수를 선택할 수 있도록 SelectableRandom 클래스를 작성하고
// 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하라.

#include <iostream>
#include "SelectableRandom.h"
using namespace std;

int main()
{
    srand((unsigned)time(0));

    SelectableRandom r1(0);

    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
    for (int i = 0; i < 10; i++)
    {
        int n = r1.next();
        cout << n << ' ';
    }


    SelectableRandom r2(1);

    cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 정수 10개 --" << endl;

    for (int i = 0; i < 10; i++)
    {
        int n = r2.nextInRange(2, 9);
        cout << n << ' ';
    }
    cout << endl;
}
