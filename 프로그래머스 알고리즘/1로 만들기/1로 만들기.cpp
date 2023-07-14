// 1로 만들기.cpp :https://school.programmers.co.kr/learn/courses/30/lessons/181880

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int size = num_list.size();
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        while (num_list[i] != 1)
        {
            ++count;
            if (num_list[i] % 2 != 0)
                --num_list[i];

            num_list[i] /= 2;
        }
    }
    return count;
}

int main()
{

}