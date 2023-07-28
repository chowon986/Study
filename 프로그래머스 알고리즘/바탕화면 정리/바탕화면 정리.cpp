// 바탕화면 정리.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/161990

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    int size = wallpaper.size();
    int startx = 51;
    int starty = 51;
    int endx = -1;
    int endy = -1;

    for (int i = 0; i < size; i++)
    {
        int curSize = wallpaper[i].size();

        for (int j = 0; j < curSize; j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (i < startx) startx = i;
                if (j < starty) starty = j;
                if (i > endx) endx = i;
                if (j > endy) endy = j;
            }
        }
    }
    vector<int> answer;
    answer.push_back(startx);
    answer.push_back(starty);
    answer.push_back(endx + 1);
    answer.push_back(endy + 1);
    return answer;
}

int main()
{

}