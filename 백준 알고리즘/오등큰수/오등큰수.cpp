#include <iostream>
#include <stack>
#include <vector>

#define MAX 1000000

using namespace std;

vector<int> numbersCount(MAX + 1);
vector<int> numbers(MAX + 1);
vector<int> ans(MAX + 1);
stack<int> s;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ++numbersCount[temp];
        numbers[i] = temp;
    }

    s.push(numbers[n - 1]);
    ans[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        int value = numbersCount[numbers[i]];
        while (!s.empty() && value >= numbersCount[s.top()])
        {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(numbers[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
}