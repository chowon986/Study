// 배열 만들기3.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181895

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals)
{
    vector<int> answer;
    int size = intervals.size();

    for (int i = 0; i < size; i++)
    {
        int startIdx = intervals[i][0];
        int endIdx = intervals[i][1];

        for (int j = startIdx; j <= endIdx; j++)
            answer.push_back(arr[j]);
    }

    return answer;
}

int main()
{

}