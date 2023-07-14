// 꼬리 문자열.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181841

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex)
{
    int size = str_list.size();
    string answer = "";

    for (int i = 0; i < size; i++)
    {
        if (str_list[i].find(ex) == string::npos)
            answer += str_list[i];
    }

    return answer;
}

int main()
{

}