// 비밀번호 발음하기

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "end")
			return 0;

		int vCount = 0; // 모음
		int ttlVCount = 0; // 전체 모음 개수
		int cCount = 0; // 자음
		bool isChecked = false;

		int size = s.size(); // string 크기
		for (int i = 0; i < size; i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				++vCount;
				++ttlVCount;
				if (vCount == 2)
				{
					if (s[i] == s[i - 1])
					{
						if(s[i] != 'e' && s[i] != 'o')
						{
							cout << '<' << s << '>' << " is not acceptable." << '\n';
							isChecked = true;
							break;
						}
					}
				}

				if(vCount >= 3)
				{
					cout << '<' << s << '>' << " is not acceptable." << '\n';
					isChecked = true;
					break;
				}
				cCount = 0;
			}
			else
			{
				++cCount;
				if (cCount == 2)
				{
					if (s[i] == s[i - 1])
					{
						cout << '<' << s << '>' << " is not acceptable." << '\n';
						isChecked = true;
						break;
					}
				}
				if(cCount >= 3)
				{
					cout << '<' << s << '>' << " is not acceptable." << '\n';
					isChecked = true;
					break;
				}

				vCount = 0;
			}
		}

		if (!isChecked)
		{
			if (ttlVCount == 0)
			{
				cout << '<' << s << '>' << " is not acceptable." << '\n';
			}
			else
			{
				cout << '<' << s << '>' << " is acceptable." << '\n';
			}
		}
	}
}