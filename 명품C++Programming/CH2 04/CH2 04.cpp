// 소수점을 가지는 5개의 실수를 입력 받아 제일 큰 수를 화면에 출력하라.

#include <iostream>
using namespace std;

int main()
{
    float a, b, c, d, e;
    cout << "5 개의 실수를 입력하라>>";
    cin >> a >> b >> c >> d >> e;
    a = max(a, b);
    b = max(c, d);
    float f = max(a, b);
    if (f > e)
    {
        cout << "제일 큰 수 = " << f;
    }
    else if(e<f)
    {
        cout << "제일 큰 수 = " << e;
    }

}
