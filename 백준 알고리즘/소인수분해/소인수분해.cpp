// 소인수분해

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> ans;

	while (n != 1)
	{
		for (int i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				ans.push_back(i);
				n /= i;
				break;
			}
		}
	}

	sort(ans.begin(), ans.end());

	for (int i : ans)
		cout << i << '\n';
}