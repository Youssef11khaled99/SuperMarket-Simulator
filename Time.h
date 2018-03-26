#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int, int);
    Time operator+(const Time&);
    friend ostream& operator<<(ostream&, const Time&);
    int getHours();
    int getMinutes();
};