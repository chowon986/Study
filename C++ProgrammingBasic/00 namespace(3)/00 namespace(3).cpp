#include <stdio.h>
#include <algorithm> // max, min 등을 포함하는 헤더

int main()
{
	int n1 = std::max(10, 20);
	int n2 = std::min(10, 20);

	printf("%d, %d\n", n1, n2);
}

// C++ 표준이 제공하는 함수 앞에는 std::를 붙여야 한다. (std namespace 안에 있으므로)
/* 
 1) int n1 = std::max(10, 20); -> 

 2) using std::max;
   int n1 = max(10, 20);

 3) using naemspace std;
   int n1 = max(10, 20);

2)와 3)보다는 1) 사용을 권장한다.
만약 3번에 전역 변수 int count = 10;를 넣고
printf("%d\n", count); 를 하면 C2872 : 'count':모호한 기호입니다. 라는 오류 발생됨
std 안에 count라는 함수가 있기 때문에 using namespace std를 한 경우 변수, 함수 중 어떤 것을
호출하는 건지 컴파일러 입장에서 명확하지 않음
*/


/* C++ header file
컴파일러에 따라 std::printf()가 정삭 작동 또는 오류가 발생된다.
해결 방법 : #include <stdio.h> -> #include <cstdio>

- C++ 표준 헤더 파일 이름에는 .h가 붙어 있지 않다.
- 사용자가 만드는 헤더는 .h를 붙여도 된다.
- C언어에서 사용하던 헤더는 C++ 버전이 별도로 제공된다.

<stdio.h> : printf등의 함수가 global namespace에 제공
<cstdio>  : printf등의 함수가 global namespace와 std namespace안에 모두 제공

C언어용 헤더를 C++ 헤더로 변경 하는 방법
.h를 빼고 앞에 c를 붙인다.

(예시)
<stdio.h> -> <cstdio>
<stdlib.h> -> <cstdlib>
<string.h> -> <cstring>
<xxxxxx.h> -> <cxxxxxx>
*/
