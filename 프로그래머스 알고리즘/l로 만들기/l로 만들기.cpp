// l로 만들기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181834

#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    int size = myString.size();

    for (int i = 0; i < size; i++)
    {
        if (myString[i] < 'l')
            myString[i] = 'l';
    }

    return myString;
}

int main()
{

}