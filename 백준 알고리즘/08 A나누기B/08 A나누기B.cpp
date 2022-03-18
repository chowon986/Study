#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cin >> a >> b;
    cout.precision(9);
    cout << fixed << (double)a / b;
}

// cout.precision(/*숫자*/)
// 자리수를 맞추어 출력하기 위한 용도
// 숫자 자리수까지 출력하도록 한다.

// fixed
// 소수점을 고정시켜 표현하겠다
