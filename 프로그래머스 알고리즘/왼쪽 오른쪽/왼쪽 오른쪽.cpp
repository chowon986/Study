// 왼쪽 오른쪽.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181890

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list)
{
    int size = str_list.size();
    vector<string> answer;

    for (int i = 0; i < size; i++)
    {
        if (str_list[i] == "l")
        {
            if (i == 0)
                return answer;

            for (int j = 0; j < i; j++)
                answer.push_back(str_list[j]);

            return answer;
        }
        else if (str_list[i] == "r")
        {
            if (i == size - 1)
                return answer;

            for (int j = i + 1; j < size; j++)
                answer.push_back(str_list[j]);

            return answer;
        }
    }

    return answer;
}

int main()
{
    vector<string> str_list = { "r"};
    solution(str_list);
}