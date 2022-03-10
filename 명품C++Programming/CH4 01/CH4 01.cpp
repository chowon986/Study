#include <iostream>
#include "Color.h"
using namespace std;

int main()
{
	Color scrrenColor(255, 0, 0);
	Color* p;
	p = &scrrenColor; // (1) p가 scrrenColor의 주소를 가지도록 코드 작성
	p->show();        // (2) p와 show()를 이용하여 screenColor 색 출력
	Color Colors[3];  // (3) Color의 일차원 배열 colors 선언. 원소는 3개
	p = Colors;		  // (4) p가 colors 배열을 가리키도록 코드 작성

	// (5) p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가
	// 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
	void Color::setColor(int r, int g, int b)
	{
		red = r;
		green = g;
		blue = b;
	}

}

