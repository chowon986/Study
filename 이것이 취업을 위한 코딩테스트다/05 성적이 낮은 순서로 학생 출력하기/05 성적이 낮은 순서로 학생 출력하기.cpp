// 05 성적이 낮은 순서로 학생 출력하기

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, string> m;

	for (int i = 0; i < n; i++)
	{
		string tString;
		int tInt;
		cin >> tString >> tInt;
		m.insert(make_pair(tInt, tString));
	}

	for (pair<int, string> it : m)
	{
		cout << it.second << ' ';
	}
}