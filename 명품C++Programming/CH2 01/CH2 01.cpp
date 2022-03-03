/*  cout과 << 연산자를 이용하여, 1에서 100까지 정ㅅ를 한줄에 10개씩 출력하라
	각 정수는 탭으로 분리하여 출력하라.
*/

#include <iostream>
using namespace std;

int main()
{
	for (int j = 0; j < 10; j++)
	{
		for (int i = 1; i < 11; i++)
		{
			cout << j * 10 + i << '\t';
		}
		cout << '\n';
	}
}