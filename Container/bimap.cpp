#include <iostream>
#include <string>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/range.hpp>
using namespace std;
using namespace boost::bimaps;

int main()
{
    {
        typedef bimap<int, string>::value_type value_t;

        bimap<int, string> b;
        b.insert(value_t(1, "one"));
        b.insert(value_t(2, "two"));
        b.insert(value_t(3, "three"));

        // This can be used key-->value from both element.
        cout << b.left.at(1) << endl;        // key: 1 --> value: "one"
        cout << b.right.at("three") << endl; // key: "three" --> value: 3
    }

    cout << "-----------" << endl;

    {
        typedef bimap<multiset_of<int>, multiset_of<int>, with_info<string>> Graph;
        typedef Graph::value_type Edge;
        Graph g;
        g.insert(Edge(0, 1, "no.1"));
        g.insert(Edge(0, 2, "no.2"));
        g.insert(Edge(1, 2, "no.3"));
        g.insert(Edge(1, 4, "no.4")); // 1 --> 4 (right of 4)
        g.insert(Edge(2, 0, "no.5"));
        g.insert(Edge(2, 3, "no.6"));
        g.insert(Edge(2, 4, "no.7")); // 2 --> 4 (right of 4)
        g.insert(Edge(3, 4, "no.8")); // 3 --> 4 (right of 4)
        g.insert(Edge(4, 0, "no.9")); // 4 --> 0 (left of 4)

        cout << boost::distance(g.left.equal_range(4)) << endl; //
        cout << boost::distance(g.right.equal_range(4)) << endl;
    }

    return 0;
}
