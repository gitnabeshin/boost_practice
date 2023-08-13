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
            cout << "Dir:   ";
        }
        else
        {
            cout << "File: ";
        }
        cout << it->path().filename() << endl;
        cout << "  path=" << it->path() << endl;
        cout << "  root_path=" << it->path().root_path();
        cout << ", root_name=" << it->path().root_name();
        cout << ", parent_path=" << it->path().parent_path();
        cout << ", is_absolute=" << it->path().is_absolute() << endl;
    }
    return 0;
}