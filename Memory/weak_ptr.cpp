#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
using namespace std;

class MyClass
{
private:
    int n;

public:
    MyClass()
    {
        n = 0;
        cout << "\t //MyClass: " << n << " created.." << endl;
    }
    MyClass(int i)
    {
        n = i;
        cout << "\t //MyClass: " << n << " created.." << endl;
    }
    ~MyClass()
    {
        cout << "\t //MyClass: " << n << " deleted.." << endl;
    }
    int get_value()
    {
        return n;
    }
};

int main()
{
    boost::shared_ptr<MyClass> sp(new MyClass(100));
    boost::weak_ptr<MyClass> wp(sp);

    // Exec proccess if this pointer is active.
    if (boost::shared_ptr<MyClass> tmp = wp.lock())
    {
        cout << "shared ptr:" << tmp->get_value() << endl;
    }
    else
    {
        cout << "already deleted.." << endl;
    }

    // delete here
    sp.reset();

    // Exec proccess if this pointer is active.
    if (boost::shared_ptr<MyClass> tmp = wp.lock())
    {
        cout << "shared ptr:" << tmp->get_value() << endl;
    }
    else
    {
        cout << "already deleted.." << endl;
    }

    cout << "----- main() End -----" << endl;
    return 0;
} // delete here
