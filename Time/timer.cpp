#include <iostream>
#include <boost/timer.hpp>
using namespace std;

int main()
{
    boost::timer t;
    unsigned int a = 0;

    cout << "start." << endl;

    for (unsigned int i = 0; i < 10000; i++)
    {
        for (unsigned int j = 0; j < 60000; j++)
        {
            a += i;
        }
    }

    cout << t.elapsed() << " sec taked time..." << endl;

    return 0;
}