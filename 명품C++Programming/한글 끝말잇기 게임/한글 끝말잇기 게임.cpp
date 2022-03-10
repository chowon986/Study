/*  n명이 하는 한글 끝말잇기 게임을 작성해보자.
    선수의 수를 입력받고, 선수의 이름을 입력받아 게임을 시작한다. */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int playerNum = 0;
    cout << "끝말 잇기 게임을 시작합니다" << endl << "게임에 참가하는 인원은 몇명입니까?";
    cin >> playerNum;
    string a ="아버지";
    string b;
    string *name = new string[100];
    for (int i = 0; i < playerNum; i++)
    {
        cout << "참가자의 이름을 입력하세요. 빈칸없이>>";
        cin >> (* (name + i));
    }
    cout << "시작하는 단어는 아버지입니다" << endl;

    while (1)
    {
        for (int i = 0; i < playerNum; i++)
        {
            cout << name[i] << ">>";
            cin >> b;
           if(a.at(4)==b.at(0))
        }

        delete name;
    }
    
}
