#include <iostream>
#include "graph.h"
#include "graph-data.h"
using namespace std;

int main()
{
    for (auto const & edges: { TADM2::Figure_5_9, TADM2::Figure_5_10 }) {
        Graph g(edges);
        cout << g;
        cout << endl;
    }

    for (auto const & edges: { CLRS3::Figure_23_1, CLRS3::Figure_24_2, CLRS3::Figure_24_4, CLRS3::Figure_24_6 }) {
        Graph g(edges);
        cout << g;
        cout << endl;
    }
}

