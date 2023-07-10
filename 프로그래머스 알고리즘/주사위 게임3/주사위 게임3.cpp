// 주사위 게임3.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181916

#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int a, int b, int c, int d)
{
    int array[7] = { 0, };

    array[a]++;
    array[b]++;
    array[c]++;
    array[d]++;

    for (int i = 1; i < 7; i++)
    {
        if (array[i] == 4)
        {
            return 1111 * i;
        }
        else if (array[i] == 3)
        {
            for (int j = 1; j < 7; j++)
            {
                if (array[j] == 1)
                {
                    return pow((10 * i + j), 2);
                }
            }
        }
        else if (array[i] == 2)
        {
            int count = 0;
            int prexNum = -1;
            for (int j = 1; j < 7; j++)
            {
                if (array[j] == 2 && i != j)
                {
                    return (i + j) * abs(i - j);
                }
                else if (array[j] == 1)
                {
                    for (int k = j + 1; k < 7; k++)
                    {
                        if (array[k] == 1)
                        {
                            return k * j;
                        }
                    }
                }
            }
        }
        else if (array[i] == 1)
        {
            for (int j = 1; j < 7; j++)
            {
                if (array[j] == 3)
                {
                    return pow((10 * j + i), 2);
                }
                else if (array[j] == 2)
                {
                    for (int k = i + 1; k < 7; k++)
                    {
                        if (array[k] == 1)
                        {
                            return i * k;
                        }
                    }
                }
            }

            return i;
        }
    }
}

int main()
{

}