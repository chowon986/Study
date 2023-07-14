// 공백으로 구분하기2.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181868

#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    int size = my_string.size();
    string cur_string;
    for (int i = 0; i < size; i++)
    {
        if (my_string[i] == ' ')
        {
            if (cur_string.size() != 0)
            {
                answer.push_back(cur_string);
                cur_string = "";
            }
        }
        else if (my_string[i] != ' ')
            cur_string += my_string[i];
    }

    if (cur_string.size() != 0)
        answer.push_back(cur_string);

    return answer;
}

int main()
{

}