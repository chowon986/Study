// 원소들의 곱과 합.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181929

#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(vector<int> num_list)
{
    int sum = 1;
    int powSum = 0;
    int lastIndex = num_list.size();

    for (int i = 0; i < lastIndex; i++)
    {
        sum *= num_list[i];
        powSum += num_list[i];
    }

    powSum = pow(powSum, 2);

    if (sum < powSum)
        return 1;

    return 0;
}

int main()
{

}