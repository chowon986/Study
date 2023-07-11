// 문자열의 앞의 n글자.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181907

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n)
{
    string answer = "";

    for (int i = 0; i < n; i++)
        answer += my_string[i];

    return answer;
}

int main()
{

}