// 특정한 문자를 대문자로 바꾸기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181873

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp)
{
    int size = my_string.size();

    for (int i = 0; i < size; i++)
    {
        if (my_string[i] == alp[0])
            my_string[i] = alp[0] - 32;
    }

    return my_string;
}

int main()
{

}