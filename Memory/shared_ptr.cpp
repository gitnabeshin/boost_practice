#include <string>
#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
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

void array_test()
{
    boost::shared_array<MyClass> str_array(new MyClass[5]);

    cout << "----- str_array() End -----" << endl;
    return;
} // delete here

int main()
{
    typedef boost::shared_ptr<MyClass> MyClassPtr;

    MyClassPtr s = MyClassPtr(new MyClass(1));
    vector<MyClassPtr> v;
    v.push_back(MyClassPtr(new MyClass(2)));
    v.push_back(MyClassPtr(new MyClass(3)));
    v.push_back(MyClassPtr(new MyClass(4)));
    v.push_back(MyClassPtr(new MyClass(5)));
    v.push_back(s);

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v.at(i)->get_value() << ", ";
    }
    cout << endl;

    cout << s->get_value() << endl;

    array_test();

    cout << "----- main() End -----" << endl;

    return 0;
}