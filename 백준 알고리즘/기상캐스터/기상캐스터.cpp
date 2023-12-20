// 기상캐스터

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<int>> b(h, vector<int>(w, -1));
	
	for (int i = 0; i < h; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < w; j++)
		{
			if (s[j] == 'c')
				b[i][j] = 0;
		}
	}

	for (int i = 0; i < h; i++)
	{
		int curCount = 0;
		bool isCloudZone = false;

		for (int j = 0; j < w; j++)
		{
			if (b[i][j] == 0)
			{
				isCloudZone = true;
				curCount = 0;
			}
			else
			{
				++curCount;
				if (isCloudZone)
					b[i][j] = curCount;
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << b[i][j] << ' ';
		cout << '\n';
	}
}