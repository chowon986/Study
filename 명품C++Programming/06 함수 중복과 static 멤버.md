# CHAPTER 06 | 함수 중복과 static 멤버 <BR>
> 6.1 함수 중복 <BR>

**중복 함수 조건**<BR>- 함수들의 이름이 동일하여야 한다.<BR>- 함수들은 매개 변수 타입이나 매개 변수의 개수가 달라야 한다.<BR>- 함수 중복에 리턴 타입은 고려되지 않는다.

```C++
#include <iostream>
using namespace std;

int sum(int a, int b) // a~b까지의 합을 구하여 리턴
{
    int s = 0;
    for(int i = a; i <= b; i++)
    {
        s += i;
    }
    return s;
}

int sum(int a) // 0~a까지의 합을 구하여 리턴
{
    int s = 0;
    for(int i = 0; i <= a; i++)
    {
        s += i;
    } 
    return s;
}

int main()
{
    cout << sum(3, 5) << endl; // 12
    cout << sum(3) << endl;    // 6
    cout << sum(100) << endl;   // 5050
}
```
<BR>

**생성자와 소멸자 함수 중복**<BR>- 생성자 함수는 중복이 가능하나, <BR>소멸자 함수는 매개 변수를 가지지 않기 때문에 한 클래스에 오직 하나만 존재한다.

<BR>

> 6.2 디폴트 매개 변수 <BR>

**디폴트 매개 변수 선언**<BR>- 매개변수 = 디폴트 값 형태로 선언됨<BR>- 디폴트 매개 변수는 모두 끝 쪽에 몰려 선언되어야 함<BR>- 중복 함수 간소화 가능
```C++
void msg(int id, string text = "Hello");

msg(10); 
// id에 10, text에 "Hello" 전달. msg(10, "Hello");로 처리됨

msg(20, "Good Morning");
// id에 20, text에 "Good Morning" 전달

msg(); // error
// 매개 변수 id에 값이 전달되지 않음

void calc(int a; int b = 5, int c, int d = 0); // 컴파일 오류
void sum(int a = 0; int b, int c); // 컴파일 오류

void calc(int a, int b = 5, int c = 0, int d = 0); // 컴파일 성공
```
<BR>

```C++
#include <iostream>
using namespace std;

void fillLine(int n = 25, char c = '*')
{
    for(int i = 0; i < n; i++)
    {
        cout << c;
    }
    cout << endl;
}

main()
{
    fillLine();
    fillLine(10, '%');
}
```
<BR>

> 6.3 함수 중복의 모호성 <BR>

**함수 중복의 모호성 종류**<BR>(1) 형 변환으로 인한 모호성<BR>(2) 참조 매개 변수로 인한 모호성<BR>(3) 디폴트 매개 변수로 인한 모호성
```C++
#include <iostream>
using namespace std;

// (1) 예시
// 오버로드된 함수 "squre"의 인스턴스 중 두 개 이상이 인수 목록과 일치합니다.
// -> 두 개의 함수 중 어떤 함수를 호출하는지 알 수 없다는 메시지
float square(float a)
{
    return a * a;
}

double square(double a)
{
    return a * a;   
}

int main()
{
    cout << square(3.0); // square(double a); 호출
    cout << square(3);   // 컴파일 오류
}

// (2) 예시
// 참조 매개 변수로 인해 함수 호출이 모호함
int add(int a, int b)
{
    return a + b;
}

int add(int a, int& b)
{
    b = b + a;
    return b;
}

int main()
{
    int s = 10;
    int t = 20;
    cout << add(s, t); // 컴파일 오류
}

// (3) 예시
// 함수 호출 모호
void msg(int id)
{
    cout << id << endl;
}

void msg(int id, string s = "")
{
    cout << id << ":" << s << endl;
}

int main()
{
    msg(5, "Good Morning"); // 정상 컴파일
    msg(6);                 // 컴파일 오류
}
```
<BR>

> 6.4 static 멤버 <BR>

**static의 특성**
<BR>- 변수와 함수의 생명 주기와 사용 범위를 지정하는 방식 중 하나<BR>

* 생명 주기 - 프로그램이 시작할 때 생성되고 프로그램이 종료할 때 소멸<BR>
* 사용 범위 - 변수나 함수가 선언된 범위 내에서 사용. 전역 혹은 지역으로 구분<BR><BR>

**static과 non-static**<BR>- static 멤버 : 모든 객체들의 공통된 멤버로서 객체 사이에 공유됨 (공기)<BR>클래스 당 하나만 생기고 모든 객체들이 공유하므로 클래스 멤버라고도 부른다. <BR>- non-static 멤버 : 객체가 생성될 때 생성되고, 각 객체마다 별도로 생성됨 (눈)<BR>각 객체마다 별도로 생성되므로 인스턴스 멤버라고 부른다.<BR><BR>

**static 멤버 선언**<BR>- 멤버 함수나 멤버 변수의 선언문 앞에 static 지정자를 붙이면 된다.<BR>- 모든 멤버들이 static으로 선언될 수 있으며, static 멤버들은 private, public, protected 등 어떤 접근 지정도 가능하다.<BR>- static 멤버 변수는 변수의 공간을 할당받는 선언문이 추가적으로 필요하다.<BR>이 선언문은 클래스 바깥의 전역 공간에 선언되어야 한다.
<BR><BR>

**접근 방법**<BR>(1) 객체이름.static멤버<BR> (2) 객체포인터->static멤버<BR> (3) 클래스명::static 멤버<BR>
요약 <BR><BR>

**특징**<BR>- static 멤버 함수는 코드 내에서 this 사용 불가<BR>- static 멤버 함수는 static 멤버 함수나 변수만 접근할 수 있으며,<BR> non-static 멤버를 접근할 수 없다. (함수 내의 지역 변수 접근은 가능)
<BR><BR>

- - -
>Open Challenge <BR>

**Up & Down 게임 만들기**<BR><BR>

> 연습문제<BR>


**실습 문제**
- - -
(참고) Open Challenge ~ 연습문제까지의 실습 내용은 Visual Studio -> 06 함수 중복과 static 멤버에 작성함