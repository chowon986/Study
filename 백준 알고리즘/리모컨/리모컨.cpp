#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int Dest;
	cin >> Dest;

	vector<int> BrokenKeys;

	int BrokenKeyCount = 1;
	for (int i = 0; i < BrokenKeyCount; i++)
	{
		int Temp;
		cin >> Temp;
		BrokenKeys.push_back(Temp);
	}

	if (Dest == 100)
	{
		cout << 0;
		return 0;
	}


}