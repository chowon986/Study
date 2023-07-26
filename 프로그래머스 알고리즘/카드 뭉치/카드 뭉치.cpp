// 카드 뭉치.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/159994

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    int size = goal.size();
    int j = 0;
    int k = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (goal[i] == cards1[j])
        {
            ++count;
            ++j;
        }

        else if (goal[i] == cards2[k])
        {
            ++count;
            ++k;
        }

        else
            return "No";
    }
    
    return "Yes";
}

int main()
{
    vector<string> cards1 = { "you", "now", "me" };
    vector<string> cards2 = { "i", "see", "to" };
    vector<string> goal = { "i", "see", "now", "me" };

    solution(cards1, cards2, goal);
}