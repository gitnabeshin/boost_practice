#include <iostream>
#include <string>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;

int main()
{
    boost::property_tree::ptree ptree;
    read_json("example.json", ptree);

    write_json(cout, ptree);
    cout << "--------------" << endl;

    cout << ptree.get<int>("Image.Width") << endl;
    cout << ptree.get<string>("Image.Thumbnail.Url") << endl;

    boost::property_tree::ptree &child = ptree.get_child("Image.IDs");
    cout << "Image.IDs: " << endl;
    BOOST_FOREACH (const boost::property_tree::ptree::value_type &e, child)
        cout << "    " << e.second.data() << endl;

    ptree.put("Image.Width", 1200);
    ptree.put("Image.Height", 960);
    ptree.put("Image.Thumbnail.Url", "Hoge");
    ptree.put("Memo", "Modified!!");
    cout << "--------------" << endl;
    write_json(cout, ptree);

    return 0;
}