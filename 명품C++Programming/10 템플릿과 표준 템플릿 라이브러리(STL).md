# CHAPTER 10 | 템플릿과 표준 템플릿 라이브러리(STL) <BR>
> 10.1 일반화와 템플릿 <BR>

**템플릿**<BR>- 형판(본 떠 찍어내기 위해 만들어진 틀)<BR>- template 키워드를 이용하면 중복 함수들을 일반화시킨 특별한 함수를 만들 수 있음<BR>->이 함수를 템플릿 함수 혹은 제너릭 함수라고 부른다.<BR><BR>
```C++
template <class T>
void myswap(T& a, T& b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 4;
    int b = 5;
    myswap(a, b);

    double c = 0.3;
    double d = 12.5;
    myswap(c, d);

    char e = 'a';
    char f = 'k';
    myswap(e, f);

    int s = 4;
    double t = 5;
    myswap(s, t); // 컴파일 오류
}
```
<BR>

**템플릿의 장단점과 제네릭 프로그래밍**<BR>- 함수 코드의 재사용을 가능하게 하여 소프트웨어의 생산성과 유연성을 높인다.<BR>- 컴파일에 따라서 템플릿이 지원되지 않을 수 있기 때문에 포팅에 취약하다.<BR>- 템플릿과 관련된 컴파일 오류 메시지가 빈약하여 디버깅에 어려움이 있다. <BR><BR>

> 10.2 다양한 제네릭 함수 만들기 <BR>

템플릿 함수와 이름이 동일한 함수가 중복되어 있을 때,<BR>컴파일러는 중복된 함수를 템플릿 함수보다 우선하여 바인딩한다.

```C++
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << array[i] << '\t';
    }
    cout << endl;
}

void print(char array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << (int)array[i] << '\t';
    }
    cout << endl;
}

int main()
{
    int x[] = {1, 2, 3, 4, 5};
    double d[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    print(x, 5);
    print(d, 5);

    char c[5] = {1, 2, 3, 4, 5};
    print(c, 5);
}

// 실행 결과
// 1     2     3     4     5
// 1.1   2.2   3.3   4.4   5.5
// 1     2     3     4     5
```
<BR>

> 10.3 제네릭 클래스 만들기 <BR>

제네릭 클래스를 만들기 위해, 클래스 선언부와 구현부를 모두 template으로 선언한다.<BR> 제네릭 클래스의 멤버 함수는 자동 제네릭 함수이다.<BR>

**제네릭 클래스의 구체화**<BR>제네릭 클래스를 이용할 때는 클래스의 이름과 함께 <BR>제네릭 타입 T에 적용할 구체적인 타입을 지정해야한다.
```C++
MyStack<int> iStack;    // int 타입을 다루는 스택 객체 생성
MyStack<double> dStack; // double 타입을 다루는 스택 객체 생성
```
**두 개의 제네릭 타입을 가진 클래스 만들기**<BR>
```C++
#include <iostream>
using namespace std;

template <class T1, class T2>
class GClass
{
    T1 data1;
    T2 data2;
public:
    GClass();
    void set(T1 a, T2 b);
    void get(T1 &a, T2 &b);
};

template <class T1, class T2>
GClass<T1, T2>::GClass()
{
    data1 = 0;
    date2 = 0;
}

template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b)
{
    data1 = a;
    data2 = b;
}

template <class T1, class T2>
void GClass<T1, T2>::get(T1& a, T2& b)
{
    a = data1;
    b = data2;
}

int main()
{
    int a;
    double b;
    GClass<int, double> x;
    x.set(2, 0.5);
    x.get(a, b);
    cout << "a=" << a << '\t' << "b=" << b << endl;

    char c;
    float d;
    GClass<char, float> y;
    y.set('m', 12.5);
    y.get(c, d);
    cout << "c=" << c << '\t' << "d=" << d << endl;
}

// 실행 결과
// a=2  b=0.5
// c=m  d=12.5
```
<BR>

>10.4 C++ 표준 템플릿 라이브러리(STL)와 활용 <BR>

**표준 템플릿 라이브러리**<BR>- 템플릿으로 작성된 많은 제네릭 클래스와 함수 라이브러리<BR>

- 컨테이너(container) - 템플릿 클래스<BR>데이터를 저장하고 검색하기 위해 담아두는 자료 구조를 구현한 클래스<BR>(리스트, 큐, 스택, 맵, 셋, 백터 등)<BR><BR>
- iterator - 컨테이너 원소에 대한 포인터<BR>반복자<BR>(원소를 읽을 때 사용하는 iterator, 원소를 기록할 때 사용하는 iterator, 둘 다 가능한 iterator 등)<BR><BR>
- 알고리즘 - 템플릿 함수<BR>컨테이너의 원소에 대한 복사, 검색, 삭제, 정렬 등의 기능을 구현한 템플릿 함수<BR><BR>

**컨테이너 분류**<BR>

- 순차 컨테이너 - vector, dequeue, list 등 연속적인 메모리 공간에 순서대로 값을 저장하고 읽는 컨테이너<BR>
- 컨테이너 어뎁터 - stack, queue 등 다른 컨테이너를 상속받아 기능 중 일부만 공개하여 기능을 제한하거나 변형한 컨테이너<BR>
- 연관 컨테이너 - set, map 등 '키'로 '값'을 저장하고, '키'로 검색하여 '값'을 알아내는 컨테이너<BR><BR>

**헤더 파일**<BR>
- STL
```C++
using namespace std;
```
- 컨테이너 클래스
```C++
// 해당 템플릿이 선언된 헤더 파일 넣기
#include <vector>
```
- 알고리즘 함수
```C++
#include <algorithm>
```
<BR>

**vector**<BR>- 객체 생성
```C++
#include <iostream>
#include <vector>

int main()
{
    vector<int> v; // int 타입의 값만 다루는 벡터 객체 생성
}
```
<BR>- vector에 원소 삽입
```C++
v.push_back(1);
v.push_back(2);
v.push_back(3);
```
<BR>- vector의 원소 값 읽기 및 변경
```C++ 
v.at(2) = 5;     // v의 3번째 원소 값을 5로 변경
int n = v.at(1); // v의 2번째 원소 값을 읽어 n에 저장
```
<BR>- vector를 배열처럼
```C++ 
v[2] = 5;     // v의 3번째 원소 값을 5로 변경
int n = v[1]; // v의 2번째 원소 값을 읽어 n에 저장
```
<BR>- vector 원소 개수 알아내기
```C++ 
// v.size()

for(int i = 0; i < v.size(); i++)
{
    cout << v[i] << endl;
}
```
<BR>- vector 원소 삭제
```C++ 
vector<int>::iterator it;
it = v.begin();
it = v.erase(it);
```
<BR>

**iterator(원소에 대한 포인터)**<BR>
```C++
// vector의 원소에 대한 iterator 변수 it 생성 
vector<int> ::iterator it;

// 벡터 v의 첫번째 원소에 대한 주소 저장
vector<int> v;
it = v.begin();

// 백터의 다음 원소 가리키기
it++;
it = it + 1;

// it이 가리키는 원소의 값 읽고 쓰기
int n = *it;
*it = 5;

// 벡터 v의 끝 가리키기
it = v.end();
```
<BR>

**map 컨테이너의 활용**<BR>
```C++
#include <map>
using namespace std;

map<string, string> dic;

// 원소 저장
dic.insert(make_pair("love", "사랑"));
dic["love"] = "사랑";

// 키로 검색하여 값 알아내기
string kor = dic["love"];

// at을 이용하여 검색하기
// -> 찾을 수 없는 경우 예외를 발생시키므로 예외 처리 필요
string kor = dic.at("love");

// eng의 키를 찾을 수 없다면 조건문은 true
if(dic.find(eng) == dic.end())
{

}
```
<BR>

> 10.5 auto와 람다식 <BR>

**auto**<BR>
변수 선언문으로부터 변수의 타입을 추론하여 결정하도록 지시
```C++
auto pi = 3.14 // pi는 double 타입으로 자동 선언
auto n = 3     // n은 int 타입으로 자동 선언
auto *p = &n   // 변수 p는 int* 타입으로 자동 선언
```
<BR>

**람다식 선언**<BR>
람다 : 이름 없는 익명 함수로 람다식 혹은 람다 함수로 불린다.
```C++
// [   ](  )->리턴타입 {함수 바디}
//  (1)  (2)
//  (1) 캡쳐리스트 (2) 매개 변수 리스트

[](int x, int y)
{
    cout << x + y;
}

[](int x, int y) -> int
{
    return x + y;
}

[](int x, int y)
{
    cout << x + y;
} (2, 3)
```
<BR>

**STL 함수 for_each()와 람다식을 이용하여 백터의 모든 원소 출력**
```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5 };

    for_each(v.begin(), v.end(), [](int n) {cout << n << " ";})
}

// 실행 결과
// 1 2 3 4 5
```
<BR>

- - -
>Open Challenge <BR>

**영어 어휘 테스트 프로그램 작성**<BR><BR>

> 연습문제<BR>


**실습 문제**
- - -
(참고) Open Challenge ~ 연습문제까지의 실습 내용은 Visual Studio -> 10 템플릿과 표준 템플릿 라이브러리에 작성함