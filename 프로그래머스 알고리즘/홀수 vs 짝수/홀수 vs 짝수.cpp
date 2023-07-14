// 홀수 vs 짝수.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181887

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int oddSum = 0;
    int evenSum = 0;
    int size = num_list.size();

    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            evenSum += num_list[i];
        else
            oddSum += num_list[i];
    }

    return evenSum > oddSum ? evenSum : oddSum;
}

int main()
{

}