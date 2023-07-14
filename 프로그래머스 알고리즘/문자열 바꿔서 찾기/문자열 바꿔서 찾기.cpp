// 문자열 바꿔서 찾기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181864

#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat)
{
    int size = myString.size();

    for (int i = 0; i < size; i++)
    {
        myString[i] = myString[i] == 'A' ? 'B' : 'A';
    }

    return myString.find(pat) != string::npos ? 1 : 0;
}

int main()
{

}