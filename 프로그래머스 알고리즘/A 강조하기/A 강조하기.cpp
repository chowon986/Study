// A 강조하기.cpp :https://school.programmers.co.kr/learn/courses/30/lessons/181874

#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    int size = myString.size();

    for (int i = 0; i < size; i++)
    {
        if (myString[i] >= 'B' && myString[i] <= 'Z')
            myString[i] += 32;
        else if (myString[i] == 'a')
            myString[i] = 'A';
    }

    return myString;
}

int main()
{

}