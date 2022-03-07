struct Rect
{
    int left;
    int top;
    int right;
    int bottom;
};

// void foo(Rect r)
void foo (const Rect& r) 
{
    // r.left = 100; error
}

#include <iostream>

int main()
{
    Rect rc = { 1,1,5,5 };
    foo(rc);
}

