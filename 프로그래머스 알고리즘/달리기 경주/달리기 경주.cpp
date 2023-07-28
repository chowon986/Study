// 달리기 경주.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/178871

/*
<이름, 순위> 값을 가지는 map
<순위, 이름> 값을 가지는 map
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    map<string, int> playersNameNum;
    map<int, string> playersNumName;
    int size = players.size();

    for (int i = 0; i < size; i++)
    {
        playersNameNum.insert(make_pair(players[i], i + 1));
        playersNumName.insert(make_pair(i + 1, players[i]));
    }

    int callingSize = callings.size();

    for (int i = 0; i < callingSize; i++)
    {
        string prevPlayerName = playersNumName[playersNameNum[callings[i]] - 1];

        swap(playersNameNum[callings[i]], playersNameNum[prevPlayerName]);
        swap(playersNumName[playersNameNum[callings[i]]], playersNumName[playersNameNum[prevPlayerName]]); 
    }

    vector<string> answer;
    for (int i = 1; i <= size; i++)
        answer.push_back(playersNumName[i]);

    return answer;
}

int main()
{
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings = { "kai", "kai", "mine", "mine" };

    solution(players, callings);
}