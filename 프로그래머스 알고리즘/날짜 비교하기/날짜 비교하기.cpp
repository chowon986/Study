// 날짜 비교하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181838

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> date1, vector<int> date2)
{
    if (date1[0] < date2[0])
        return 1;
    else if (date1[0] > date2[0])
        return 0;
    else if (date1[1] < date2[1])
        return 1;
    else if (date1[1] > date2[1])
        return 0;
    else if (date1[2] < date2[2])
        return 1;
    else if (date1[2] > date2[2])
        return 0;

    return 0;
}

int main()
{

}