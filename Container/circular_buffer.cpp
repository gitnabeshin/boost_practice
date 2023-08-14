#include <iostream>
#include <boost/circular_buffer.hpp>
using namespace std;

void print_buf(boost::circular_buffer<int> *buf)
{
    for (int i = 0; i < buf->size(); i++)
    {
        cout << " [" << i << "]:" << buf->at(i);
    }
    cout << endl;
}

int main()
{
    boost::circular_buffer<int> buf(4);

    buf.push_back(1);
    buf.push_back(2);
    buf.push_back(3);
    buf.push_back(4);
    print_buf(&buf);

    buf.push_front(5);
    print_buf(&buf);

    buf.push_front(6);
    print_buf(&buf);

    buf.pop_back();
    print_buf(&buf);

    buf.pop_front();
    print_buf(&buf);
}