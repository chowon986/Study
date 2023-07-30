// 햄버거 만들기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/133502

#include <string>
#include <vector>

using namespace std;

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient)
{
    vector<int> value;
    int answer = 0;

    int size = ingredient.size();

    for (int i = 0; i < size; i++)
    {
        value.push_back(ingredient[i]);

        if (value.back() == 1 && value.size() >= 4)
        {
            int lastIdx = value.size() - 1;

            if (value[lastIdx - 1] == 3 &&
                value[lastIdx - 2] == 2 &&
                value[lastIdx - 3] == 1)
            {
                for(int j = 0; j < 4; j++)
                    value.pop_back();

                ++answer;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> ingredient = { 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 3, 1, 3, 1 };
    solution(ingredient);
}
