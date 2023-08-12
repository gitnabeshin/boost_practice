#include <boost/progress.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>

int main()
{
    const int MAX = 1000;

    boost::progress_display show_progress(MAX);

    for (int i = 0; i < MAX; i++)
    {
        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
        ++show_progress;
    }
    return 0;
}
