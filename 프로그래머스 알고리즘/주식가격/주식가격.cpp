// 주식가격.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;
    int size = prices.size();
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = i + 1; j < size; j++)
        {
            if (prices[i] <= prices[j])
                ++count;
            else
            {
                ++count;
                break;
            }
        }
        answer.push_back(count);
    }

    return answer;
}

int main()
{

}