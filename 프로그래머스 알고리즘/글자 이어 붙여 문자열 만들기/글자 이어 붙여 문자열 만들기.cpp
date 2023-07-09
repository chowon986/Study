// 글자 이어 붙여 문자열 만들기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181915

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> index_list)
{
    int size = index_list.size();
    string answer = "";

    for (int i = 0; i < size; i++)
    {
        answer += my_string[index_list[i]];
    }

    return answer;
}

int main()
{

}