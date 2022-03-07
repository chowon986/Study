// 다음 코드에서 Box 클래스의 선언부와 구현부, main()를 분리하여 전체 프로그램을 완성하라.

#include <iostream>
#include "Box.h"
using namespace std;

int main()
{
	Box b(10, 2);
	b.draw();
	cout << endl;
	b.setSize(7, 4);
	b.setFill('^');
	b.draw();
}
