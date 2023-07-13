// rny_string.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181863

#include <string>
#include <vector>

using namespace std;

string solution(string rny_string)
{
    int size = rny_string.size();
    string answer;

    for (int i = 0; i < size; i++)
    {
        if (rny_string[i] == 'm')
            answer += "rn";
        else
            answer += rny_string[i];
    }

    return answer;
}

int main()
{

}