/*  "yes"가 입력될 때까지 종료하지 않는 프로그램을 작성하라.
	사용자로부터의 입력은 cin.getline() 함수를 사용하라  */

#include <iostream>
using namespace std;

int main()
{
	char a[100];

	while (1)
	{
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(a, 100, '\n');
		if (a[0] == 'y' && a[1] == 'e' && a[2] == 's')
		{
			cout << "종료합니다. . .";
			break;
		}
	}
}

