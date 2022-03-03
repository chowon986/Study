/*  문자열을 두 개 이력받고 두 개의 문자열이 같은지 검사하는 프로그램을 작성하라.
    만일 같으면 "같습니다." 아니면 "같지 않습니다."를 출력하라  */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    string b;
    cout << "새 암호를 입력하세요>>";
    cin>>a;
    cout << "새 암호를 다시 한 번 입력하세요>>";
    cin >> b;
    if (a == b)
    {
        cout << "같습니다.";
    }
    else
    {
        cout << "같지 않습니다.";
    }
}
