#include <iostream>
#include <string>
using namespace std;

// Base class
class Clock
{
protected:
    int hour;

public:
    Clock(int h)
    {
        hour = h;
    }

    void display(string city)
    {
        cout << city << " time: ";

        if (hour < 10)
            cout << "0";

        cout << hour << ":00" << endl;
    }
};

// Derived class
class WorldClock : public Clock
{
public:
    WorldClock(int h) : Clock(h) {}
};

// PersonalWorldClock class
class PersonalWorldClock
{
private:
    Clock modesto;
    WorldClock london;

public:
    PersonalWorldClock() : modesto(10), london(18) {}

    void showTimes()
    {
        modesto.display("Modesto");
        london.display("London");
    }
};

int main()
{
    PersonalWorldClock myClock;
    myClock.showTimes();

    return 0;
}