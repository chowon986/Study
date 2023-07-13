// 대문자로 바꾸기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181877

#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    int size = myString.size();

    for (int i = 0; i < size; i++)
    {
        if (myString[i] >= 97)
            myString[i] -= 32;
    }

    return myString;
}

int main()
{

}