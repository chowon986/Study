// 원하는 문자열 찾기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181878

#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    int size = myString.size();
    
    for(int i = 0; i < size; i++)
        myString[i] = tolower(myString[i]);

    size = pat.size();

    for (int i = 0; i < size; i++)
        pat[i] = tolower(pat[i]);

    if (myString.find(pat) != string::npos)
        return 1;

    return 0;
}

int main()
{
    string myString = "AbCdEfG";
    string pat = "aBc";

    solution(myString, pat);
}