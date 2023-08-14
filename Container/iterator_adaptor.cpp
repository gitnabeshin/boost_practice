#include <iostream>
#include <algorithm>
#include <boost/iterator_adaptors.hpp>
using namespace std;
using namespace boost;

class MyLinkedList
{
    MyLinkedList *next;
    int data;

public:
    MyLinkedList(MyLinkedList *n, int d)
    {
        next = n;
        data = d;
    }

    struct iterator : iterator_adaptor<
                          iterator,              // Derived
                          MyLinkedList *,        // Base
                          int,                   // Value
                          forward_traversal_tag> // CategoryOrTraversal
    {
        iterator(MyLinkedList *p)
            : iterator_adaptor(p) {}
        void increment()
        {
            base_reference() = base()->next;
        }
        int &dereference() const
        {
            return base_reference()->data;
        }
    };

    iterator begin()
    {
        return iterator(this);
    }
    iterator end()
    {
        return iterator(NULL);
    }
};

void print(int x)
{
    cout << x << endl;
}

int main()
{
    MyLinkedList f(NULL, 60); // end
    MyLinkedList e(&f, 50);
    MyLinkedList d(&e, 40);
    MyLinkedList c(&d, 30);
    MyLinkedList b(&c, 20);
    MyLinkedList a(&b, 10); // begin

    for_each(a.begin(), a.end(), print);
    cout << "-------------" << endl;

    MyLinkedList y(&d, 200);
    MyLinkedList x(&y, 100); // begin

    for_each(x.begin(), x.end(), print);

    return 0;
}