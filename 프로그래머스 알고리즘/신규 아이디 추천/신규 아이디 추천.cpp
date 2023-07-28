// 신규 아이디 추천.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <cctype>
#include <vector>

using namespace std;

string solution(string new_id)
{
    int size = new_id.size();
    string answer = "";
    vector<char> recommendedID;

    for (int i = 0; i < size; i++)
    {
        char temp = tolower(new_id[i]);

        if ((temp >= 97 && temp <= 122) || 0 != isdigit(temp) || temp == '-' || temp == '_' || temp == '.')
        {
            if (recommendedID.size() == 0)
            {
                if (temp == '.')
                    continue;
                else
                {
                    recommendedID.push_back(temp);
                    continue;
                }
            }

            if (recommendedID.back() == '.' && temp == '.')
                continue;
            
            recommendedID.push_back(temp);
        }
    }

    if (recommendedID.size() != 0)
    {
        while (recommendedID.back() == '.')
            recommendedID.pop_back();
    }

    int newSize = recommendedID.size();

    if (newSize == 0)
    {
        recommendedID.push_back('a');
    }

    if (newSize > 15)
    {
        vector<char> newWord;

        for (int i = 0; i < 15; i++)
        {
            newWord.push_back(recommendedID[i]);
        }

        while (newWord.back() == '.')
            newWord.pop_back();

        int newWordSize = newWord.size();
        for (int i = 0; i < newWordSize; i++)
            answer += newWord[i];
    }

    else if (newSize < 3)
    {
        char lastWord = recommendedID.back();

        while (recommendedID.size() != 3)
            recommendedID.push_back(lastWord);

        for (int i = 0; i < 3; i++)
            answer += recommendedID[i];
    }
    else
    {
        for (int i = 0; i < newSize; i++)            
            answer += recommendedID[i];
    }

    return answer;
}

int main()
{
    solution("=.=");
}