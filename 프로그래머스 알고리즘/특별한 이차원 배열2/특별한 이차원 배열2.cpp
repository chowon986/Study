// 특별한 이차원 배열2.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181831

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr)
{
    int columnSize = arr.size();
    int rowSize = arr[0].size();
    for (int i = 0; i < columnSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            if (arr[i][j] != arr[j][i])
                return 0;
        }
    }

    return 1;
}

int main()
{

}