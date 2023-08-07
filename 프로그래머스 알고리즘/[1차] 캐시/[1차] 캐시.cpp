// [1차] 캐시.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/17680

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    if (cacheSize == 0)
        return cities.size() * 5;

    list<string> value;
    value.resize(cacheSize, "");
    int size = cities.size();
    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        int tempSize = cities[i].size();
        for (int j = 0; j < tempSize; j++)
        {
            if (cities[i][j] >= 'A' && cities[i][j] <= 'Z')
                cities[i][j] = cities[i][j] + 32;
        }
	}

	for (int i = 0; i < size; i++)
	{
		if (find(value.begin(), value.end(), cities[i]) == value.end())
		{
			value.pop_back();
			value.push_front(cities[i]);
			answer += 5;
		}
		else // 현재 cache에 값이 있다면
		{
			list<string>::iterator curit = find(value.begin(), value.end(), cities[i]);
			value.erase(curit);
			value.push_front(cities[i]);
			answer += 1;
		}
	}

	return answer;
}

int main()
{
    solution(3, { "a", "b", "c", "a", "b", "d", "c" });
}