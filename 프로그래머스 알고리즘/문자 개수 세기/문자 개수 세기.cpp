// 문자 개수 세기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181902

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string)
{
    vector<int> answer;
    answer.resize(52);
    int size = my_string.size();

    for (int i = 0; i < size; i++)
    {
        if ('A' <= my_string[i] &&
            my_string[i] <= 'Z')
        {
            ++answer[my_string[i] - 'A'];
        }
        else
        {
            ++answer[my_string[i] - 'G'];
        }
    }

    return answer;
}

int main()
{
    solution("Programmers");
}