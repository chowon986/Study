// 부분 문자열 이어 붙여 문자열 만들기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181911

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts)
{
    int size = my_strings.size();
    string answer = "";

    for (int i = 0; i < size; i++)
    {
        for (int j = parts[i][0]; j <= parts[i][1]; j++)
        {
            answer += my_strings[i][j];
        }
    }

    return answer;
}

int main()
{

}