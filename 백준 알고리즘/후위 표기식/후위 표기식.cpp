#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> operators;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            cout << s[i];
        else
        {
            if (s[i] == ')')
            {
                while (operators.top() != '(')
                {
                    cout << operators.top();
                    operators.pop();
                }
                operators.pop();
            }
            else if (s[i] == '(')
                operators.push(s[i]);
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!operators.empty() && (operators.top() == '/' || operators.top() == '*'))
                {
                    cout << operators.top();
                    operators.pop();
                }
                operators.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    cout << operators.top();
                    operators.pop();
                }
                operators.push(s[i]);
            }
        }
    }

    while (!operators.empty())
    {
        cout << operators.top();
        operators.pop();
    }
}