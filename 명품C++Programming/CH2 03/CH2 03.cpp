// 키보드로부터 두 개의 정수를 읽어 큰 수를 화면에 출력하라.

#include <iostream>
using namespace std;

int main()
{
	int num1 = 0;
	int num2 = 0;
	cout << "두 수를 입력하라>>";
	cin >> num1 >> num2;
	cout << "큰 수 = " << max(num1, num2);
}
