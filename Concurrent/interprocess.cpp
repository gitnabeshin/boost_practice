#include <iostream>
#include <string>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
using namespace std;
using namespace boost::interprocess;

struct Foo
{
    int a, b, c;
    Foo(int i, int j, int k)
    {
        a = i;
        b = j;
        c = k;
    }
};

static const char *NAME = "MySharedMemory";

int main(int argc, char *argv[])
{
    if (argc == 2 && std::string(argv[1]) == "remove")
    {
        // remove shm
        shared_memory_object::remove(NAME);
    }
    else
    {
        // create or get shm
        managed_shared_memory shm(open_or_create, NAME, 1024);
        // create or get mutex
        interprocess_mutex *mx = shm.find_or_construct<interprocess_mutex>("TheMutex")();
        Foo *pFoo = shm.find_or_construct<Foo>("TheFoo")(0, 0, 0);

        // Lock from here
        boost::interprocess::scoped_lock<interprocess_mutex> lock(*mx);
        pFoo->a += 1;
        pFoo->b += 2;
        pFoo->c += 3;
        cout << pFoo->a << " " << pFoo->b << " " << pFoo->c << endl;

        // Unlock automatically
    }

    return 0;
}