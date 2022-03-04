/*  CoffeeMachine 클래스를 만들어보자. main() 함수와 실행 결과가 다음과 같도록 CoffeeMachine 클래스를 작성하라.
    에스프레소 한 잔에는 커피와 물이 각각 1씩 소비되고, 
    아메리카노의 경우 커피는 1, 물은 2가 소비되고,
    설탕 커피는 커피 1, 물 2, 설탕 1이 소비된다.
    CoffeeMachine 클래스에는 어떤 멤버 변수와 어떤 멤버 함수가 필요한지 잘 판단하여 작성하라.
*/

#include <iostream>
#include "CoffeeMachine.h"
using namespace std;

int main()
{
    CoffeeMachine java(5, 10, 3); // 커피 5 물 10 설탕 3으로 초기화
    java.drinkEspresso();
    java.show();
    java.drinkAmericano();
    java.show();
    java.drinkSugarCoffee();
    java.show();
    java.fill();
    java.show();
}
