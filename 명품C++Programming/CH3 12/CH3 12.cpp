// CH3 12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Ram.h"
using namespace std;

int main() 
{
    Ram ram;
    ram.write(100, 20); 
    ram.write(101, 30);  
    char res = ram.read(100) + ram.read(101); 
    ram.write(102, res); 
    cout << "102 번지의 값 = " << (int)ram.read(102) << endl; // 102 번지 값 출력 
}
