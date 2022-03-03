/*  한 라인에 ';'으로 5개의 이름을 구분하여 입력받아,
	각 이름을 끊어 화면에 출력하고 가장 긴 이름을 찾아라  */

// strlen() : 문자열의 길이를 구하는 함수
// strcopy(a,b) : b 문자열의 내용을 a 에 복사
#include <iostream>
using namespace std;

int main()
{
	char name[100];
	char max[100];
	int count = 0;

	cout << "5 명의 이름을 ';'으로 구분하여 입력하세요" << '\n' << ">>";

	for (int i = 0; i < 5; i++)
	{
		cin.getline(name, 100, ';');
		cout << i+1 << " : " << name<<'\n';
		
		if (strlen(name) > count) 
		{
			count = (int)strlen(name); 
			strcpy_s(max, name); // 가장 긴 이름을 max[100]에 copy
		}
	}

	cout << "가장 긴 이름은 "<<max;
}