// ASynchronous I/O

#include <iostream>
#include <string>
#include <boost/asio.hpp>
using namespace std;
using namespace boost::asio;

int main()
{
    ip::tcp::iostream s("www.google.com", "http");

    s << "GET / HTTP/1.0\r\n";
    s << "Host: www.google.com\r\n";
    s << "\r\n";
    s << flush;

    string line;
    while (getline(s, line))
    {
        cout << line << endl;
    }

    return 0;
}
