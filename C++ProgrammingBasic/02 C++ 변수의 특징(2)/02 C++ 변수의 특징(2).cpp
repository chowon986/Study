#include <iostream>

// typedef int DWORD;
// typedef void(*PF)(int);

using DWORD = int;
using PF = void(*)(int);

int main()
{
    DWORD n; // int n;
    PF p; // void(*p)(int)
    
    // typedef vs using
    // typedef : type에 대한 별칭
    // using : type에 대한 별칭 + template 에 대한 별칭
}

