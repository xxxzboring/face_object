#include <iostream>
#include <iomanip>

using namespace std;

class Date {
public:
    Date(int y = 1900, int m = 1, int d = 1);
    void Init(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void display();
    int calWeekday();
    bool isLeapYear();
    void nextDay();

private:
    int year;
    int month;
    int day;

    static bool isValidDate(int y, int m, int d);
    static int daysInMonth(int y, int m);
    static void printDate(int y, int m, int d);
};

Date::Date(int y, int m, int d) : year(1900), month(1), day(1)
{
    if (isValidDate(y, m, d)) {
        year = y;
        month = m;
        day = d;
    } else {
        cout << "Invalid date: " << y << "-" << m << "-" << d
             << ", set to 1900-01-01" << endl;
    }
}

void Date::Init(int y, int m, int d)
{
    if (isValidDate(y, m, d)) {
        year = y;
        month = m;
        day = d;
    } else {
        cout << "Invalid date: " << y << "-" << m << "-" << d
             << ", keep the old value" << endl;
    }
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::setYear(int y)
{
    if (y < 1) {
        cout << "Invalid year: " << y << ", ignored" << endl;
        return;
    }
    if (!isValidDate(y, month, day)) {
        cout << "Invalid year: " << y << ", ignored" << endl;
        return;
    }
    year = y;
}

void Date::setMonth(int m)
{
    if (!isValidDate(year, m, day)) {
        cout << "Invalid month: " << m << ", ignored" << endl;
        return;
    }
    month = m;
}

void Date::setDay(int d)
{
    if (!isValidDate(year, month, d)) {
        cout << "Invalid day: " << d << ", ignored" << endl;
        return;
    }
    day = d;
}

void Date::display()
{
    cout << "Date: ";
    printDate(year, month, day);
    cout << endl;
}

int Date::calWeekday()
{
    int y = year;
    int m = month;
    if (m == 1 || m == 2) {
        m += 12;
        y -= 1;
    }
    int w = (day + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    return (w + 7) % 7;
}

bool Date::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::nextDay()
{
    if (day < daysInMonth(year, month)) {
        ++day;
    } else if (month < 12) {
        day = 1;
        ++month;
    } else {
        day = 1;
        month = 1;
        ++year;
    }
}

bool Date::isValidDate(int y, int m, int d)
{
    if (y < 1 || m < 1 || m > 12 || d < 1)
        return false;
    return d <= daysInMonth(y, m);
}

int Date::daysInMonth(int y, int m)
{
    static const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        return 29;
    return days[m];
}

void Date::printDate(int y, int m, int d)
{
    cout << y << "-" << setfill('0') << setw(2) << m << "-"
         << setw(2) << d << setfill(' ');
}

int main()
{
    static const char *WEEK[] = {"星期日", "星期一", "星期二", "星期三",
                                 "星期四", "星期五", "星期六"};

    int y, m, d;
    cout << "Input year month day:" << endl;
    cin >> y >> m >> d;

    Date date(y, m, d);
    date.display();
    cout << "Weekday: " << WEEK[date.calWeekday()] << endl;

    return 0;
}
