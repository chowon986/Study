// N과 M (6)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> isUsed(10, false);
vector<int> numbers;
vector<int> newNumbers(10, 0);

void go(int index, int start, int count)
{
	if (index == count)
	{
		for (int i = 0; i < index; i++)
		{
			cout << newNumbers[i] << ' ';
		}

		cout << '\n';
		return;
	}

	for (int i = start; i < numbers.size(); i++)
	{
		if (isUsed[i]) continue;

		isUsed[i] = true;

		newNumbers[index] = numbers[i];
		go(index + 1, i + 1, count);
		isUsed[i] = false;
	}
}

int main()
{
	int tc, count;
	cin >> tc >> count;

	for (int i = 0; i < tc; i++)
	{
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());
	go(0, 0, count);
}