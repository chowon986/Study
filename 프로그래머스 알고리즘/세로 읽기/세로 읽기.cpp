// 세로 읽기.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/181904

#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c)
{
    int size = my_string.size();
	char word[1000][1000];
	int curIdx = 0;

	for (int i = 0; i < size / m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			word[i][j] = my_string[curIdx++];
		}
	}

	string answer = "";

	for (int i = 0; i < size / m; i++)
	{
		answer += word[i][c - 1];
	}

    return answer;
}

int main()
{
	solution("ihrhbakrfpndopljhygc", 4, 2);
}