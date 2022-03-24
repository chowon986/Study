/* 00 STL 컨테이너

STL: C++ 언어가 제공하는 표준라이브러리
STL이 제공하는 것들
- list, stack, queue, tree 등의 자료 구조
- sort, binary, search 등의 알고리즘
- 날짜, 시간 등의 다양한 유틸리티 클래스
- thread, concurrency 등

Linked List, Stack, Queue와 같은(자료구조) 컨테이너,
자료 내의 내용들을 정렬, 검색 등 알고리즘,
자료구조과 알고리즘을 연결하는 포인터와 유사한 객체인 반복자로 구성되어 있다.

컨테이너의 종류 :
선형 컨테이너 :
vector는 연속된 것, list는 떨어져있는거
연관 컨테이너 :
map

컨테이너의 특징 :
(1) 대부분 컨테이너의 멤버함수의 이름이 동일하다.
->대부분의 코드를 수정하지 않고도 컨테이너를 교체할 수 있다.

push_front(), push_back(), insert(), erase() 등을 사용하여 자료를 넣거나 뺄 수 있다.

단, vector는 push_front()가 없다.
vector는 배열처럼 사용 가능([] 사용 가능)
------------------------------------------------ -
(2) 제거와 반환을 동시에 하지 않는다.
- pop_front(), pop_back() 함수는 제거만 하고
- front(), back() 함수는 반환만 한다.

std::list<int> s1; // 리스트 한개 만들기
std::list<int> s2(10); // 10개를 0으로 초기화
std::list<int> s3(10, 3) // 10개를 3으로 초기화
std::list<int c4{ 10,3 } // 2개를 10, 3으로 초기화 (직접 초기화)
	std::list<int>c5 = { 10,3 } (복사 초기화)

	모든 요소 출력하는 방법
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 }
v.push_back(20);
(1) 배열처럼
for (int i = 0; i < v.size(); i++)
{
	std::cout << v[i] << std::endl;
}

(2) range for 사용
for (auto& n : v)
{
	std::cout << n << std::endl;
}

(3) 반복자 사용
*/