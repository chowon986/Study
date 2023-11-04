#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    stack<char> cs;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (cs.size() > 0)
            {
                if (s[i - 1] == ')')
                {
                    ++cnt;
                    cs.pop();
                }
                else
                {
                    cs.pop();
                    cnt += cs.size();
                }
            }
        }
        else
            cs.push('(');
    }

    cout << cnt;
}