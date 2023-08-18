// N과 M (4)

#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers(10, 0);

void go(int index, int start, int maxNum, int count)
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

	for (int i = start; i <= maxNum; i++)
	{
		numbers[index] = i;
		go(index + 1, i, maxNum, count);
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	go(0, 1, a, b);
}