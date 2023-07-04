// 이어 붙인 수.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181928

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    string sumOddNum = "";
    string sumEvenNum = "";
    int size = num_list.size();

    for (int i = 0; i < size; i++)
    {
        if (num_list[i] % 2 == 0)
            sumEvenNum += to_string(num_list[i]);
        else
            sumOddNum += to_string(num_list[i]);
    }

    return stoi(sumEvenNum) + stoi(sumOddNum);
}


int main()
{
    vector<int> num_list = { 3, 4, 5, 2, 1 };
    solution(num_list);
}
