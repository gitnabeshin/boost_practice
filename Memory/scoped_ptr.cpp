#include <string>
#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
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
};

int main()
{
    boost::scoped_ptr<string> s(new string("scoped_ptr Test..."));
    cout << *s << endl;

    boost::scoped_ptr<MyClass> my_c(new MyClass(1));

    boost::scoped_array<MyClass> my_array(new MyClass[5]);

    cout << "----- main() End -----" << endl;
    return 0;
} // delete here
