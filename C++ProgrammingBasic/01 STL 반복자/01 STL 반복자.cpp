/* 01 STL 반복자
 
반복자 : 포인터와 유사하게 동작하는 객체로서 반복자를 사용하면 컨테이너의 모든 요소를 순차적으로 접근할 수 있다.

컨테이너의 내부 구조(메모리 구조)에 상관없이 동일한 방법으로 요소에 접근할 수 있다.
(link, vector 상관 없음)

std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
auto p2 = v.begin();
++p2;
*p2 = 20;
++p2;
std::cout<<*p2<<std::endl; // 3

반복자의 데이터 이름
-> 컨테이너이름::iterator
std::vector<int>::iterator p1 = v.begin();
std라는 namespace안에 vector라는 클래스가 있는데 그 안에 내포되어있는 iterator타입

end()로 얻는 반복자는 컨테이너의 마지막 다음을 가리킨다.
-> 끝을 지난 반복자(past the end)
-> end()로 얻는 반복자를 사용해서 요소에 접근하면 안된다.
-> 끝에 도달했는지 확인하는 용도

반복자를 꺼내는 방법
멤버함수 : v.begin(), v.end()
(배열은 사용 불가)
일반함수 : std::begin(v), std::end(v)
(배열도 사용 가능)

for( auto& n : v)
v에서부터 요소를 하나씩 꺼내서 n에 넣어줘


*/