// 개인정보 수집 유효기간.cpp : https://school.programmers.co.kr/learn/courses/30/lessons/150370

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    int termsSize = terms.size();
    map<char, int> termsMap;

    // 오늘 날짜 구하기
    string tempWord = "";
    int curYear = -1;
    int curMonth = -1;
    int curDay = -1;
    for (int i = 0; i < 10; i++)
    {
        if (today[i] == '.')
        {
            if (curYear == -1) curYear = stoi(tempWord);
            else if (curMonth == -1) curMonth = stoi(tempWord);
            tempWord = "";
        }
        else
            tempWord += today[i];
    }

    curDay = stoi(tempWord);

    // 약관 종류, 유효기간을 map으로 정리
    for (int i = 0; i < termsSize; i++)
    {
        string tempWord = "";
        int tempSize = terms[i].size();
        char alphabet = terms[i][0];
        int month = -1;
        string tempMonth = "";

        for (int j = 2; j < tempSize; j++)
        {
            tempMonth += terms[i][j];
        }

        month = stoi(tempMonth);
        termsMap.insert(make_pair(alphabet, month));
    }

    // 유효기간을 더한 값 구하기
    int privaciesSize = privacies.size();

    for (int i = 0; i < privaciesSize; i++)
    {
        int calcuratedYear = -1;
        int calcuratedMonth = -1;
        int calcuratedDay = -1;

        int tempSize = 10;
        string tempWord = "";

        for (int j = 0; j < tempSize; j++)
        {
            if (privacies[i][j] == '.')
            {
                if (calcuratedYear == -1) calcuratedYear = stoi(tempWord);
                else if (calcuratedMonth == -1) calcuratedMonth = stoi(tempWord);

                tempWord = "";
            }
            else
                tempWord += privacies[i][j];
        }

        calcuratedDay = stoi(tempWord);

        // 약관의 기간만큼 month 증가
		calcuratedMonth += termsMap[privacies[i][11]];

		if (calcuratedMonth > 12)
		{
            if (calcuratedMonth % 12 == 0)
            {
                calcuratedYear = calcuratedYear + ((calcuratedMonth / 12) - 1);
                calcuratedMonth = 12;
            }
            else
            {
                calcuratedYear = calcuratedYear + (calcuratedMonth / 12);
                calcuratedMonth = (calcuratedMonth % 12);
            }
		}

		if (calcuratedDay > 1)
            calcuratedDay -= 1;
        else
        {
            calcuratedDay = 28;
            if (calcuratedMonth > 1)
                calcuratedMonth -= 1;
            else
            {
                calcuratedMonth = 12;
                calcuratedYear -= 1;
            }
        }

        if (calcuratedYear < curYear)
            answer.push_back(i + 1);
        else if (calcuratedYear == curYear)
        {
            if (calcuratedMonth < curMonth)
                answer.push_back(i + 1);
            else if (calcuratedMonth == curMonth)
            {
                if (calcuratedDay < curDay)
                    answer.push_back(i + 1);
            }
        }
    }

    return answer;
}

int main()
{
    //입력값 〉 "2020.12.17", ["A 12"], ["2010.01.01 A", "2019.12.17 A"]
    //    기댓값 〉[1, 2]

    //    입력값 〉 "2020.01.01", ["A 1"], ["2019.12.01 A"]
    //    기댓값 〉[1]

    //    입력값 〉 "2020.04.16", ["A 36", "S 4"], ["2017.04.17 A", "2014.04.16 S"]
    //    기댓값 〉[2]

    //입력값 〉 "2016.02.15", ["A 100"], ["2000.06.16 A", "2008.02.15 A"]
    //    기댓값 〉[1]
    //    기존의 코드
    //    입력값 〉 "2019.12.09", ["A 12"], ["2018.12.10 A", "2010.10.10 A"]
    //    기댓값 〉[2]

    string today = "2020.01.01";
    vector<string> terms = { "A 1" };
    vector<string> privacies = { "2019.12.01 A" };
    solution(today, terms, privacies);
}