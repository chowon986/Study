// qr code.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181903

#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code)
{
    int size = code.size();
    string answer = "";

    for (int i = 0; i < size; i++)
    {
        if (i % q == r)
            answer += code[i];
    }

    return answer;
}

int main()
{
    solution(3, 1, "qjnwezgrpirldywt");
}