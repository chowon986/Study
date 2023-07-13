// 배열에서 문자열 대소문자 변환하기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181875

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    int size = strArr.size();

    for (int i = 0; i < size; i++)
    {
        int unitSize = strArr[i].size();

        for (int j = 0; j < unitSize; j++)
        {
            if (i % 2 == 0)
            {
                if (strArr[i][j] < 97)
                    strArr[i][j] += 32;
            }
            else
            {
                if (strArr[i][j] >= 97)
                    strArr[i][j] -= 32;
            }
        }
    }

    return strArr;
}

int main()
{
    vector<string> strArr = { "AAA","BBB","CCC","DDD" };
    solution(strArr);
}