// Person 클래스와 main() 함수를 작성하여 3개의 Person 객체를 가지는 배열을 선언하고,
// 이름과 전화번호를 입력받아 출력하고 검색하는 프로그램을 완성하라

#include <iostream>
#include <string>
using namespace std;

class Person
{
	string name;
	string tel;
public:
	Person()
	{

	}
	string getName()
	{
		return name;
	}
	string getTel()
	{
		return tel;
	}
	void set(string name, string tel)
	{
		this->name = name;
		this->tel = tel;
	}
};
int main()
{
	string name[3];
	string tel[3];
	Person ppl[3];
	string search;

	cout << "이름과 전화 번호를 입력해 주세요" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "사람 " << i+1 << ">> ";
		cin >> name[i] >> tel[i];
		ppl[i].set(name[i], tel[i]);
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++)
	{
		cout << name[i]<<' ';
	}
	cout << endl << "전화번호를 검색합니다. 이름을 입력하세요>>";
	cin >> search;

	cout << "전화 번호는 ";
	for (int i = 0; i < 3; i++)
	{
		if (ppl[i].getName() == search)
		{
			cout<<ppl[i].getTel();
		}
	}

}
