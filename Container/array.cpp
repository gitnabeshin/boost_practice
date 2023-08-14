#include <iostream>
#include <algorithm>
#include <boost/array.hpp>
using namespace std;

int main()
{
    boost::array<int, 100> iArray;
    for (int i = 0; i < iArray.size(); i++)
    {
        iArray[i] = i * 100;
    }

    boost::array<int, 4> iArray2 = {{0, 100, 200, 300}};

    // iArray2: [0, 100, 200, 300]
    // iArray : [0, 100, 200, 300, 400, 500, ,,,, 10000]
    if (equal(iArray2.begin(), iArray2.end(), iArray.begin()))
    {
        cout << "Arrays are Same between " << iArray2[0] << " and " << iArray2[iArray2.size() - 1] << endl;
    }

    cout << " iArray.size()=" << iArray.size() << endl;
    cout << "iArray2.size()=" << iArray2.size() << endl;

    return 0;
}