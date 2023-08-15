#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<bool> prime(1000001, 1);
    prime[1] = 0;

    for (int i = 2; i * i < 1000001; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i + i; j < 1000001; j += i)
                prime[j] = 0;
        }
    }
    

    for (int i = m; i <= n; i++)
    {
        if (prime[i] == 1)
            cout << i << '\n';
    }
}