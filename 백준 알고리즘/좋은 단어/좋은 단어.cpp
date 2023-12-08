// 좋은 단어

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		stack<char> s;

		int size = temp.size();

		for(int j = 0; j < size; j++)
		{
			if (!s.empty())
			{
				if (s.top() == temp[j])
					s.pop();
				else
					s.push(temp[j]);
			}
			else
				s.push(temp[j]);
		}

		if (s.empty())
			++count;
	}

	cout << count;
}