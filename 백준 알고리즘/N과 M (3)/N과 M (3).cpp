// N과 M (3)

#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers(10, 0);

void go(int index, int maxNum, int count)
{
	if (index == count)
	{
		for (int i = 0; i < index; i++)
		{
			cout << numbers[i] << ' ';
		}

		cout << '\n';
		return;
	}

	for (int i = 1; i <= maxNum; i++)
	{
		numbers[index] = i;
		go(index + 1, maxNum, count);
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	go(0, a, b);
}