#include <iostream>
#include <string>
#include <boost/thread.hpp>
using namespace std;

class MyClass
{
    typedef boost::mutex::scoped_lock lock;
    volatile bool end_flg;
    boost::mutex mutex_myclass;
    boost::condition_variable_any exit_request;

public:
    MyClass()
    {
        end_flg = false;
    }

    // run as thread
    void my_main()
    {
        for (;;)
        {
            lock lk(mutex_myclass);
            if (end_flg)
            {
                break;
            }

            boost::xtime xt;
            boost::xtime_get(&xt, boost::TIME_UTC_);
            xt.sec += 3;

            if (exit_request.timed_wait(lk, xt))
            {
                // end
                break;
            }
            else
            {
                // wait
                cout << "\nWrite something..." << flush;
            }
        }
    }

    void stop()
    {
        lock lk(mutex_myclass);
        end_flg = true;
        exit_request.notify_one();
    }
};

int main()
{
    MyClass mc;
    // thread start
    boost::thread th(&MyClass::my_main, &mc);

    cout << "Write something...";
    string str;
    getline(cin, str); // wait input

    mc.stop();

    th.join();

    cout << "Thank you!!! [" << str << "]" << endl;

    return 0;
}