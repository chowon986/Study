// N과 M (2)

#include <vector>
#include <iostream>
using namespace std;

vector<bool> c(10, false); // 앞에서 사용한 수인지?
vector<int> a(10, false); // 수열을 저장

void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < index; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		if (c[i]) continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, i + 1, n, m);
		c[i] = false;
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	go(0, 1, a, b);
}