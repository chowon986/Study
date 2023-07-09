// 문자열의 뒤의 n글자.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181910

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n)
{
    int size = my_string.size();
    int startIdx = size - n;
    string answer = "";

    for (int i = startIdx; i < size; i++)
    {
        answer += my_string[i];
    }

    return answer;
}

int main()
{

}