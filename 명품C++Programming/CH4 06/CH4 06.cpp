#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text;
	cout << "아래에 한 줄을 입력하세요.(exit을 입력하면 종료합니다)" << endl;
	while (1)
	{
		cout << ">>";
		getline(cin, text, '\n');
		if (text.compare("exit") == 0)
		{
			break;
		}
		reverse(text.begin(), text.end());
		cout << text << endl;
	}
}
