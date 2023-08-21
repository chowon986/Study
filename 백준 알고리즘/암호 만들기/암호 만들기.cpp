// 암호 만들기

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//vector<char> alpha;
//
//bool check(string password)
//{
//	int a = 0; int b = 0;
//	for (int i = 0; i < password.size(); i++)
//	{
//		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
//			++a;
//
//		else ++b;
//	}
//
//	return (a >= 1 && b >= 2);
//}
//
//void go(int n, vector<char>& alpha, string password, int i)
//{
//	if (password.length() == n)
//	{
//		if (check(password))
//		{
//			cout << password << '\n';
//		}
//		return;
//	}
//
//	if (i >= alpha.size()) return;
//	go(n, alpha, password + alpha[i], i + 1);
//	go(n, alpha, password, i + 1);
//}
//
//int main()
//{
//	// n 만들어야 하는 암호의 길이
//	// alpha 사용할 수 있는 알파벳
//	// password 현재까지 만든 암호
//	// i 사용할지 말지 결정해야 하는 알파벳의 인덱스
//	int n, m;
//	cin >> n >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		char character;
//		cin >> character;
//		alpha.push_back(character);
//	}
//
//	sort(alpha.begin(), alpha.end());
//
//	go(n, alpha, "", 0);
//}

//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool check(string password)
//{
//    int ja = 0;
//    int mo = 0;
//    for (int i = 0; i < password.length(); i++)
//    {
//        if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
//            ++mo;
//        else
//            ++ja;
//    }
//
//    return (mo >= 1 && ja >= 2);
//}
//
//void go(int n, vector<char>& alpha, string password, int i)
//{
//    if (password.length() == n)
//    {
//        if (check(password))
//        {
//            cout << password << '\n';
//        }
//        return;
//    }
//
//    if (i >= alpha.size()) return;
//    go(n, alpha, password + alpha[i], i + 1);
//    go(n, alpha, password, i + 1);
//}
//
//int main()
//{
//    vector<char> alpha;
//    int n, m;
//    cin >> n >> m;
//
//    for (int i = 0; i < m; i++)
//    {
//        char temp;
//        cin >> temp;
//        alpha.push_back(temp);
//    }
//
//    sort(alpha.begin(), alpha.end());
//
//    go(n, alpha, "", 0);
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> word;
vector<char> newWord(26);

bool check(vector<char>& password, int index)
{
	int mo = 0;
	int ja = 0;
	for (int i = 0; i < index; i++)
	{
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u')
			++mo;
		else
			++ja;
	}

	return (mo >= 1 && ja >= 2);
}

void go(int index, int count, int start)
{
	if (index == count)
	{
		if (check(newWord, index))
		{
			for (int i = 0; i < index; i++)
			{
				cout << newWord[i];
			}

			cout << '\n';
		}
		return;
	}

	for (int i = start; i < word.size(); i++)
	{
		newWord[index] = word[i];
		go(index + 1, count, i + 1);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		char character;
		cin >> character;
		word.push_back(character);
	}

	sort(word.begin(), word.end());

	go(0, n, 0);
}