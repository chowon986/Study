// Date 클래스 만들기.cpp : 

#include <iostream>

class Date
{
    int year_;
    int month_;
    int day_;

public:
    void SetDate(int year, int month, int date)
    {
        year_ = year;
        month_ = month;
        day_ = date;
    }

    void AddDay(int inc)
    {
        day_ += inc;

        if (month_ == 2)
        {
            AddMonth(day_ / 28);
            day_ %= 28;
        }
        else if (month_ % 2 == 0 && month_ != 8)
        {
            AddMonth(day_ / 30);
            day_ %= 30;
        }
        else
        {
            AddMonth(day_ / 31);
            day_ %= 31;
        }
    }

    void AddMonth(int inc)
    {
        month_ += inc;

        if (month_ > 12)
        {
            AddYear(month_ / 12);
            month_ %= 12;
        }
    }

    void AddYear(int inc)
    {
        year_ += inc;
    }

    void ShowDate()
    {
        std::cout << year_ << '.' << month_ << '.' << day_;
    }
};

int main()
{
    Date date;

    date.SetDate(2012, 2, 28);
    date.AddDay(3);
    date.ShowDate();
}