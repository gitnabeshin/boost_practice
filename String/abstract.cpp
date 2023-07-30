#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;

int main()
{
    using boost::lexical_cast;

    string str_thousand = "1000";
    int int_ninety = 90;

    // convert
    int a = lexical_cast<int>(str_thousand);
    string s = lexical_cast<string>(int_ninety);

    cout << a + 111 << endl;
    cout << s << "[" << s.length() << "]" << endl;

    return 0;
}