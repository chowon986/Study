// 그림 확대.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181836

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k)
{
    vector<string> answer;
    int size = picture.size();
    answer.resize(size * k);
    int q = 0;

    for (int i = 0; i < size; i++)
    {
        int tempSize = picture[i].size();
        for (int j = 0; j < tempSize; j++)
        {
            for (int a = 0; a < k; a++)
                answer[q] += picture[i][j];
        }

        for (int p = 0; p < k; p++)
        {
            answer[q + p] = answer[q];
        }
        q += k;
    }

    return answer;
}

int main()
{

}