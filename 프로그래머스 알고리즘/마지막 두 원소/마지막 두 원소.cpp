// 마지막 두 원소 : https://school.programmers.co.kr/learn/courses/30/lessons/181927

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list)
{
    int lastIndex = num_list.size() - 1;
    int newValue = 0;

    if (num_list[lastIndex] > num_list[lastIndex - 1])
    {
        newValue = num_list[lastIndex] - num_list[lastIndex - 1];
    }
    else
    {
        newValue = num_list[lastIndex] * 2;
    }

    num_list.push_back(newValue);

    return num_list;
}

int main()
{
    vector<int> num_list = { 2,1,6 };
    solution(num_list);
}