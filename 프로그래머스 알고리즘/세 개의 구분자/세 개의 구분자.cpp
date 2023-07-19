// 세 개의 구분자.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181862

#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr)
{
    vector<string> answer;
    int size = myStr.size();
    string tempWord = "";

    for (int i = 0; i < size; i++)
    {
        if (myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c')
        {
            if (tempWord != "")
            {
                answer.push_back(tempWord);
                tempWord = "";
            }
        }
        else
            tempWord += myStr[i];
    }

    if (tempWord != "")
        answer.push_back(tempWord);

    if (answer.size() == 0)
        answer.push_back("EMPTY");

    return answer;
}

int main()
{

}