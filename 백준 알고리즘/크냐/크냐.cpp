// 크냐

#include <iostream>
using namespace std;

int main()
{
	int n, m;
	while (true)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		string ans = n > m ? "Yes" : "No";
		cout << ans << endl;
	}
}