#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
using namespace std;

struct MyData
{
    vector<string> vec;
    int num;
    double pi;

private:
    // Impl Serializarion
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, unsigned int ver)
    {
        ar &vec;
        ar &num;
        ar &pi;
    }
};

int main()
{
    // Save
    {
        MyData data;
        data.num = 100;
        data.pi = 3.14;
        data.vec.push_back("Hello");
        data.vec.push_back("World");

        ofstream file("save.dat");
        boost::archive::text_oarchive oa(file);
        oa << (const MyData &)data;
    }

    // Restore
    {
        MyData data;
        ifstream file("save.dat");
        boost::archive::text_iarchive ia(file);
        ia >> data;

        cout << data.num << endl;
        cout << data.pi << endl;
        for (size_t i = 0; i < data.vec.size(); i++)
        {
            cout << data.vec.at(i).c_str() << endl;
        }
    }

    return 0;
}
