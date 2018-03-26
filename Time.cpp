#include "Time.h"

Time::Time() : hours(0), minutes(0) {}

Time::Time(int h, int m) : hours(h), minutes(m) {}

Time Time::operator+(const Time& obj)
{
    Time temp;
    temp.hours = hours + obj.hours;
    temp.minutes = minutes + obj.minutes;
    if(temp.minutes > 59)
    {
        temp.hours += temp.minutes/60;
        temp.minutes %= 60;
    }
    if(temp.hours > 23) temp.hours %= 24;
    return temp;
}

ostream& operator<<(ostream& out,const Time& t)
{
    out<<(t.hours > 9 ? "" : "0") << t.hours<<":"<<(t.minutes > 9 ? "" : "0")<<t.minutes<<endl;
}

int Time::getHours()
{
    return hours;
}

int Time::getMinutes()
{
    return minutes;
}

