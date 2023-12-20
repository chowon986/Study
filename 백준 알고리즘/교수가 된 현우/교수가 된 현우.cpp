// 교수가 된 현우

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		int copyTemp = temp;
		int ans = 0;

		// 숫자를 5로 나눈다.
		temp /= 5;
		ans += temp;

		// 숫자를 25로 나눈다.
		copyTemp /= 25;
		ans += copyTemp;

		// 25로 나누어지면 더 다눈다.
		while (temp / 25 != 0)
		{
			temp /= 25;
			ans += temp;
		}

		while (copyTemp / 25 != 0)
		{
			copyTemp /= 25;
			ans += copyTemp;
		}

		cout << ans << '\n';
	}
}