// 오큰수

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1000000

vector<int> numbers(MAX + 1, 0);
vector<int> ans(MAX + 1, 0);

int main()
{
    int n;
    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers[i] = temp;
    }

    s.push(numbers[n - 1]);
    ans[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        int value = numbers[i];

        // 스택이 비어있지 않고, 스택의 top이 value 보다 작거나 같으면
        // 그 수는 버린다
        while (!s.empty() && value >= s.top())
        {
            s.pop();
        }

        ans[i] = s.empty() ? -1 : s.top();
        s.push(value);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
}