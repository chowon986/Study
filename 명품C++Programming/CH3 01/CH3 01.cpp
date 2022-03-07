// main()의 실행 결과가 높이는 1미터, 높이는 100미터로 나오도록 Tower 클래스를 작성하라

#include <iostream>
#include "Tower.h"
using namespace std;


int main()
{

	Tower myTower; // 1미터
	Tower seoulTower(100); // 100미터

	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;

}