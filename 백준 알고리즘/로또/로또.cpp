// 로또

#include <iostream>
#include <vector>
using namespace std;

vector<int> newNumbers(50, 0);

void go(vector<int>& numbers, int index, int count, int start)
{
	if (index == count)
	{
		for (int i = 0; i < index; i++)
		{
			cout << newNumbers[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = start; i < numbers.size(); i++)
	{
		newNumbers[index] = numbers[i];
		go(numbers, index + 1, count, i + 1);
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			return 0;

		vector<int> numbers(n);

		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;

			numbers[i] = temp;
		}

		go(numbers, 0, 6, 0);
		cout << "\n";
	}
}