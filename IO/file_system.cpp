#include <iostream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>
using namespace std;

int main()
{
    namespace fs = boost::filesystem;

    fs::path dir("my_dir");
    fs::create_directory(dir);
    fs::ofstream f(dir / "test.txt");
    f << "Hello!" << endl;
    f.close();

    fs::directory_iterator end;
    for (fs::directory_iterator it(fs::current_path()); it != end; ++it)
    {
        if (fs::is_directory(*it))
        {
            cout << "D ";
        }
        else
        {
            cout << "F ";
        }
        cout << it->path().filename() << endl;
    }
    return 0;
}