// 추억 점수 : https://school.programmers.co.kr/learn/courses/30/lessons/176963

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    // name과 yearning 연결
    map<string, int> allYearnings;
    int nameSize = name.size();

    for (int i = 0; i < nameSize; i++)
    {
        allYearnings.insert(make_pair(name[i], yearning[i]));
    }


    int photoSize = photo.size();

    for (int i = 0; i < photoSize; i++)
    {
        int curPhotoSize = photo[i].size();
        int curYearnings = 0;

        for (int j = 0; j < curPhotoSize; j++)
        {
            auto it = allYearnings.find(photo[i][j]);
            if (it != allYearnings.end())
                curYearnings += it->second;
        }

        answer.push_back(curYearnings);
    }

    return answer;
}

int main()
{
    vector<string> name = { "may", "kein", "kain", "radi" };
    vector<int> yearning = { 5, 10, 1, 3 };
    vector<vector<string>> photo = { {"may", "kein", "kain", "radi"} ,{"may", "kein", "brin", "deny"},{"kon", "kain", "may", "coni"} };

    solution(name, yearning, photo);
}