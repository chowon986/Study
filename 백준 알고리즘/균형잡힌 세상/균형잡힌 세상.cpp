// 균형잡힌 세상

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	while (true)
	{
		getline(cin, s);
		if (s == ".")
			return 0;

		if (s[0] == ')' || s[0] == ']')
		{
			cout << "no" << '\n';
		}
		else
		{
			bool isYes = true;
			stack<char> st;

			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '(' || s[i] == '[')
				{
					st.push(s[i]);
				}
				else if (s[i] == ')')
				{
					if (st.empty())
						isYes = false;
					else if (st.top() == '(')
						st.pop();
					else
						isYes = false;
				}
				else if (s[i] == ']')
				{
					if (st.empty())
						isYes = false;
					else if (st.top() == '[')
						st.pop();
					else
						isYes = false;
				}
			}

			if (st.empty() && isYes)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
	}
}