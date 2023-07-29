// 공원 산책.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/172928

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes)
{
    int parkSize = park.size();
    int curX = -1;
    int curY = -1;
    int heightSize = parkSize;
    int widthSize = park[0].size();

    for (int i = 0; i < parkSize; i++)
    {
        bool isfound = false;
        int tempSize = park[i].size();

        for (int j = 0; j < tempSize; j++)
        {
            if (park[i][j] == 'S')
            {
                curX = j;
                curY = i;
                isfound = true;
                break;
            }
        }

        if (isfound)
            break;
    }

    int routesSize = routes.size();

    for (int i = 0; i < routesSize; i++)
    {
		int range = (routes[i][2] - '0');
        bool isBreaked = false;

        if (routes[i][0] == 'E')
        {
            for (int j = 1; j <= range; j++)
            {
                if (curX + j >= widthSize) {
                    isBreaked = true;
                    break;
                }
                if ('X' == park[curY][curX + j]) {
                    isBreaked = true;
                    break;
                }
            }

            if(!isBreaked)
                curX += (routes[i][2] - '0');
        }
        else if (routes[i][0] == 'W')
        {
            for (int j = 1; j <= range; j++)
            {
                if (curX - j < 0) {
                    isBreaked = true;
                    break;
                }
                if ('X' == park[curY][curX - j]) {
                    isBreaked = true;
                    break;
                }
            }

            if (!isBreaked)
                curX -= (routes[i][2] - '0');
        }
        else if (routes[i][0] == 'N')
        {
            for (int j = 1; j <= range; j++)
            {
                if (curY - j < 0) {
                    isBreaked = true;
                    break;
                }
                if ('X' == park[curY - j][curX]) {
                    isBreaked = true;
                    break;
                }
            }

            if (!isBreaked)
                curY -= (routes[i][2] - '0');
        }
        else if (routes[i][0] == 'S')
        {
            for (int j = 1; j <= range; j++)
            {
                if (curY + j >= heightSize) {
                    isBreaked = true;
                    break;
                }
                if ('X' == park[curY + j][curX]) {
                    isBreaked = true;
                    break;
                }
            }

            if (!isBreaked)
                curY += (routes[i][2] - '0');
        }
    }

    vector<int> answer;
    answer.push_back(curY);
    answer.push_back(curX);
    return answer;
}

int main()
{
    vector<string> park = { "OSO","OOO","OXO","OOO" };
    vector<string> routes = { "E 2","S 3","W 1" };
    solution(park, routes);
}