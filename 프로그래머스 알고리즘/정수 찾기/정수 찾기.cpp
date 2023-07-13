// 정수 찾기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181840

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n)
{
    for (int curNum : num_list)
    {
        if (curNum == n)
            return 1;
    }

    return 0;
}

int main()
{

}