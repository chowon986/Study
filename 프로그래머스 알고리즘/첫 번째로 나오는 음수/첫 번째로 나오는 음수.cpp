// 첫 번째로 나오는 음수.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181896

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int size = num_list.size();

    for (int i = 0; i < size; i++)
    {
        if (num_list[i] < 0)
            return i;
    }

    return -1;
}

int main()
{

}