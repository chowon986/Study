// 카펫.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int totalCount = yellow + brown;
    vector<int> answer;

    for (int i = 2; i <= brown; i++)
    {
        if (i - 2 == yellow)
        {
            if (i * 2 + 2 == brown)
            {
                answer.push_back(i);
                answer.push_back(3);
                return answer;
            }
        }
    }

    for (int i = 2; i <= brown; i++)
    {
        if (yellow % i == 0)
        {
            int height = yellow / i;
            if (i * 2 + ((height + 2) * 2) == brown)
            {
                answer.push_back(height + 2);
                answer.push_back(i + 2);
                return answer;
            }
        }
    }

    return answer;
}

int main()
{

}