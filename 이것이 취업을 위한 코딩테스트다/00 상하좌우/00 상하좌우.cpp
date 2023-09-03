// 00 상하좌우

#include <iostream>
#include <string>
using namespace std;

char a[101];
int xPos[4] = { -1, 1, 0, 0 };
int yPos[4] = { 0, 0, -1, 1 }; 

int main()
{
	int n;
	cin >> n;

	int curX = 1;
	int curY = 1;

	cin.ignore();
	string temp;
	getline(cin, temp);

	for(int i = 0; i < temp.size(); i++)
	{
		int value = -1;
		if (temp[i] == 'U') value = 0;
		if (temp[i] == 'D') value = 1;
		if (temp[i] == 'L') value = 2;
		if (temp[i] == 'R') value = 3;

		if (value != -1)
		{
			if ((curX + xPos[value] > 0 && curY + yPos[value] > 0) &&
				(curX + xPos[value] <= n && curY + yPos[value] <= n))
			{
				curX += xPos[value];
				curY += yPos[value];
			}
		}
	}

	cout << curX << ' ' << curY;
}