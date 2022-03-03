// <Enter> 키가 입력될 때까지 문자들을 읽고, 입력된 문자 'x'의 개수를 화면에 출력하라

#include <iostream>
using namespace std;

int main()
{
	char text[100];
	int sum = 0;
	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(text, 100, '\n');
	for (int i = 0; i < 100; i++)
	{
		if (text[i] == 'x'|| text[i] == 'X')
		{
			++sum;
		}
	}
	cout << "x의 개수는 " << sum;
}

