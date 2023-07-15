// x 사의의 개수.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181867

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString)
{
    int count = 0;
    int size = myString.size();
    vector<int> answer;

    for (int i = 0; i < size; i++)
    {
        if (myString[i] != 'x')
            ++count;
        else
        {
            answer.push_back(count);
            count = 0;
        }
    }
    answer.push_back(count);

    return answer;
}

int main()
{

}