#include <iostream>
#include <string>
#include <boost/flyweight.hpp>
using namespace std;

int main()
{
    boost::flyweight<string> a("abc");
    boost::flyweight<string> b("abc");
    boost::flyweight<string> c(a.get() + b.get());
    boost::flyweight<string> d("abcabc");

    // share the string "abc", "abcabc"
    cout << &a << ": " << &a.get() << ": " << a << endl;
    cout << &b << ": " << &b.get() << ": " << b << endl;
    cout << &c << ": " << &c.get() << ": " << c << endl;
    cout << &d << ": " << &d.get() << ": " << d << endl;
}
