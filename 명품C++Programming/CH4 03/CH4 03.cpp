// string 클래스를 이용하여 빈칸을 포함하는 문자열을 입력받고 문자열에서 'a'가 몇개 있는지 출력하는 프로그램을 작성해라
#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "문자열 입력>>";
	char crt = 'a';
	int len = 0;
	string text;
	int num = 0;

	getline(cin, text, '\n');
	len = (int)text.length();

	for (int i = 0; i < len; i++)
	{
		if (text.at(i) == crt)
		{
			++num;
		}
	}

	// (1)
	cout << "문자 " << crt << "는 " << num << "개 있습니다."<<endl;

	num = 0;
	int index = 0;
	while (1)
	{
		index = text.find('a', index);
		if (index == -1)
		{
			break;
		}
		index++;
		num++;
	}
	// (2)
	cout << "문자 " << crt << "는 " << num << "개 있습니다.";

}
