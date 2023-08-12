#define DATE_TIME_INLINE
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace std;

int main()
{
    using namespace boost::gregorian;

    date dx(2025, 8, 11);
    cout << dx << endl;
    cout << dx.year() << "." << dx.month() << "." << dx.day() << endl;

    date d1(day_clock::local_day());
    cout << "Today: " << d1;

    date d2 = d1 + date_duration(100);

    date_duration dd = d2 - d1;
    cout << " until " << d2 << " will more " << dd.days() << " days." << endl;

    return 0;
}