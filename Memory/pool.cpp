#include <iostream>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
using namespace std;

struct Abc
{
    Abc()
    {
        static int no = 0;
        cout << "Abc() :" << (m_no = ++no) << endl;
    }
    ~Abc() { cout << "~Abc():" << m_no << endl; }
    int m_no;
};

int main()
{
    {
        boost::pool<> p(sizeof(int));
        int *px = (int *)p.malloc();
        int *py = (int *)p.malloc();
        int *pz = (int *)p.malloc();
        *px = 10;
        p.free(pz);

        // No need to call free() of all
    }

    {
        boost::object_pool<Abc> p;
        Abc *pstrx = p.construct();
        Abc *pstry = p.construct();
        Abc *pstrz = p.construct();
        p.destroy(pstry);

        // No need to call destroy() of all
    }
    return 0;
}