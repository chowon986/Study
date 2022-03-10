// string 클래스를 이용하여 사용자가 입력한 영문 한 줄을 입력받고 글자 하나만 랜덤하게 수정하여 출력하는 프로그램을 작성하라

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	srand((unsigned)time(0));

	string x;
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl << ">>";
	getline(cin, x, '\n');
	
	if (x.compare("exit") == 0)
	{
		return 0;
	}

	int n = rand() % x.size();
	char a = rand() % 25 + 97;

	while (1)
	{
		if (a != ' ')
		{
			break;
			a = rand() % 25 + 97;
		}
	}

	x[n] = (char)a;
	cout << x;

	return 0;

}
