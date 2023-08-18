// N과 M (8)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
		newNumbers[index] = numbers[i];
		go(index + 1, i, count);
	}
}

int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		int temp;
		cin >> temp;

		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());

	go(0, 0, b);
}