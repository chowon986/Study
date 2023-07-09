// 문자열 여러 번 뒤집기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries)
{
    int queriesSize = queries.size();

    for (int i = 0; i < queriesSize; i++)
    {
        int startIdx = queries[i][0];
        int endIdx = queries[i][1];

        std::reverse(my_string.begin() + startIdx, my_string.begin() + endIdx + 1);
    }

    return my_string;
}

int main()
{
    solution("rermgorpsam", { {2, 3},{0, 7},{5, 9},{6, 10} });

}