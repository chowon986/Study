// 배열 만들기2.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181921

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r)
{
    vector<int> answer;

    for (int i = l; i <= r; i++)
    {
        string temp = to_string(i);
        int size = temp.size();
        bool isTrue = true;

        for (int j = 0; j < size; j++)
        {
            if (temp[j] != '5' && temp[j] != '0')
            {
                isTrue = false;
                break;
            }
        }

        if (isTrue == true)
            answer.push_back(i);
    }

    if (answer.size() == 0)
        answer.push_back(-1);

    return answer;
}

int main()
{

}