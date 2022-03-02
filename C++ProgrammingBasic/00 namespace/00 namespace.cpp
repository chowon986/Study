// namespace
// 관련된 코드(함수, 구조체, 전역 변수 등)를 묶어서 관리하는 방법
// 서로 다른 이름 공간에서는 동일한 이름을 사용할 수 있다.

// (예시)
// 하나의 프로젝트를 여러 명의 개발자가 같이 개발하고 있는데,
// Audio 루틴을 만드는 개발자와 Video 루틴을 만드는 개발자가 각각 init이라는 이름의 함수를 만들려고 한다.

/*
#include <stdio.h>

void init()
{
	printf("init Audio module\n");
}

void init()
{
	printf("init Video module\n");
}

int main()
{
	init();
}

*/
// (오류)
// (1) C2084 'void init(void)' 함수에 이미 본문이 있습니다. -> namespace를 만들어 해결 가능
// (2) C2065 'init': 선언되지 않은 식별자입니다. -> 어떤 namespace 내 함수인지 명확히 알려주면 해결 가능

#include <stdio.h>

namespace Audio //(1)
{
	void init()
	{
		printf("init Audio module\n");
	}
}

namespace Video //(1)
{
	void init()
	{
		printf("init Video module\n");
	}
}

int main()
{
	// init(); error
	Audio::init(); //(2)
	Video::init(); //(2)
}

/* namespace의 요소에 접근하는 방법
 1) 완전한 이름(qualified name) 사용
	Audio::init();

 2) using 선언(declaration) 사용
	using Audio::init;
	init();
	-> namespace Audio 내 다른 함수가 있고, 그 함수를 호출하는 경우 오류 발생
	// reset(); error

 3) using 지시어(directive) 사용
	using namespace Audio;
	init();

2)와 3)은 추가적인 이름 충돌의 가능성이 있으므로 방법 1)을 사용하는 것이 좋다.
*/

