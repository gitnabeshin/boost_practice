#include <iostream>
#include <boost/progress.hpp>
using namespace std;

int main()
{
    boost::progress_timer t;

    unsigned int a = 0;
    for (unsigned int i = 0; i < 10000; i++)
    {
        for (unsigned int j = 0; j < 30000; j++)
        {
            a += i;
        }
    }

    cout << "end main()." << endl;
    return 0;
} // destructor t called and show the progress time.