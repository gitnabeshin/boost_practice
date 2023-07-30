#include <iostream>
#include <boost/format.hpp>
using namespace std;

int main()
{

    cout << boost::format("%1% %2%") % "hello" % 100 << endl;
    cout << boost::format("%2% %1%") % "hello" % 100 << endl;

    cout << boost::format("%05d %x %f") % 200 % 255 % 0.33 << endl;
    cout << boost::format("30%% OFF") << endl;

    return 0;
}