// 영화감독 숌.cpp 

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int curFilmName = 666;
	int curCount = 1;

	while (curCount != n)
	{
		++curFilmName;

		string temp = to_string(curFilmName);

		int cnt = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == '6')
			{
				++cnt;
				if (cnt == 3)
					break;
			}
			else
				cnt = 0;
		}

		if (cnt == 3)
			++curCount;
	}

	cout << curFilmName;
}