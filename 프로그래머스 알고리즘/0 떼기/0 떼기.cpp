// 0 떼기.cpp :https://school.programmers.co.kr/learn/courses/30/lessons/181847

#include <string>
#include <vector>

using namespace std;

string solution(string n_str)
{
    string answer = "";
    int size = n_str.size();
    bool alreadyHaveZero = false;

    for (int i = 0; i < size; i++)
    {
        if (n_str[i] == '0' && !alreadyHaveZero)
        {
        }
        else
        {
            answer += n_str[i];
            alreadyHaveZero = true;
        }
    }

    return answer;
}

int main()
{

}