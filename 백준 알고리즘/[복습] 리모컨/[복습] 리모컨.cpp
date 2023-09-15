// [복습] 리모컨

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MAX 1000000

vector<bool> isBroken(10, false);

int main()
{
	int curChannel = 100;
	int targetChannel, brokenCount;
	cin >> targetChannel >> brokenCount;

	for (int i = 0; i < brokenCount; i++)
	{
		int temp;
		cin >> temp;
		isBroken[temp] = true;
	}

	int maxMove = abs(curChannel - targetChannel);

	int copy = targetChannel;
	int temp = copy;
	while (temp >= 0)
	{
		// 고장난 채널이면
		if (isBroken[temp % 10])
		{
			--copy;
			temp = copy;
		}
		else
		{
			temp /= 10;

			if (temp == 0)
			{
				break;
			}
		}
	}

	int tempButtonCount;
	int buttonCount;

	if (temp < 0)
	{
		buttonCount = MAX;
	}
	else
	{
		tempButtonCount = to_string(copy).size();
		buttonCount = tempButtonCount + (targetChannel - copy);
	}


	copy = targetChannel;
	temp = copy;
	while (temp <= MAX)
	{
		// 고장난 채널이면
		if (isBroken[temp % 10])
		{
			++copy;
			temp = copy;
		}
		else
		{
			temp /= 10;

			if (temp == 0)
			{
				break;
			}
		}
	}

	tempButtonCount = to_string(copy).size();

	buttonCount = min(buttonCount, tempButtonCount + (copy - targetChannel));
	buttonCount = min(maxMove, buttonCount);

	cout << buttonCount;
}