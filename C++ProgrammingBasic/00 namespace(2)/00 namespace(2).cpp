#include <stdio.h>

namespace Video
{
    void init()
    {
        printf("init Video module\n");
    }
}

namespace Audio
{
    void init()
    {
        printf("init Audio module\n");
    }
}

void init()
{
    printf("init global module\n");
}

int main()
{
    Video::init(); // init Video module
    Audio::init(); // init Audio module

    ::init(); // init global module
    init(); // init global module
}

/* ::init();과 init();의 차이점
::init()은 항상 global을 의미
init()은 달라질 수 있다.

(예시)
using Audio::init;
::init(); // init global module
init(); // init Audio module

global void init()을 주석 처리하면
::init(); // error 발생 (찾을 수 없음)

(정리)
- init()
(1) 열려 있는 namespace 검색
(2) global namespace 검색

- ::init()
(1) global namespace 검색
(2) global init()이 없는 경우 에러
------------------------------------------
using declaration을 함수 밖에서 사용한 경우
-> using 선언 아래 있는 "모든 함수에서 Audio::이름 없이 접근 가능"
-> global namespace에 동일 이름의 함수가 있을 경우 error
   : 호출 원하는 함수가 global 인지 namespace에 있는 건지 알 수 없으므로
-> global namespace에 동일 이름의 함수가 없을 경우 init(), ::init() 모두 Audio::init() 호출
*/

