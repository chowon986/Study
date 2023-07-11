// 공백으로 구분하기1.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181869

#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string)
{
    vector<string> answer;
    int size = my_string.size();
    string temp = "";

    for (int i = 0; i < size; i++)
    {
        if (my_string[i] == ' ')
        {
            answer.push_back(temp);
            temp = "";
        }
        else
            temp += my_string[i];
    }

    answer.push_back(temp);

    return answer;
}

int main()
{

}