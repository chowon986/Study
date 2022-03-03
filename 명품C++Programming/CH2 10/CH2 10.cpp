/*  문자열을 하나 입력받고 문자열의 부분 문자열을 다음과 같이 출력하는 프로그램을 작성해라
ex) 문자열 입력 >> hello
	h
	he
	hel
	hell
	hello
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	char text[100];
	int a = 0;
	cout << "문자열 입력>>";
	cin >> text;

	a = (int)strlen(text);

	for (int i = 1; i < a + 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << text[j];
		}
		cout << endl;
	}
}
