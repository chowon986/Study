/*  날짜를 다루는 Date 클래스를 작성하고자 한다.
    Date를 이용하는 main()과 실핼 결과는 다음과 같다.
    클래스 Data를 작성하여 아래 프로그램에 추가하라  */

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date birth(2014, 3, 20); // 2014년 3월 20일
    Date independenceDay("1945/8/15"); // 1945년 8월 15일
    independenceDay.Show();
    cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}

// 힌트 : <string> 헤더 파일의 stoi() 함수를 이용하면 string의 문자열을 숫자로 변환할 수 있다.
// stoi()는 C++11 표준부터 삽입되었다.