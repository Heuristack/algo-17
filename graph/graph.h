#ifndef GRAPH_H
#define GRAPH_H

#include <ostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

template <typename Vertex, typename Edge = Vertex> using BasicGraph = map<Vertex, set<Edge>>;
template <typename Vertex> struct Graph : BasicGraph<Vertex>
{
    Graph(vector<pair<Vertex, Vertex>> const & E)
    {
        for (auto const & e : E) {
            this->operator[](e.first).emplace(e.second);
            this->operator[](e.second).emplace(e.first);
        }
    }

    ostream & puts(ostream & s)
    {
        for (auto const & v : *this) {
            s << v.first << ": ";
            for (auto const & w : v.second) {
                s << w << " ";
            }
            s << "\n";
        }
        return s;
    }
};
template <typename Vertex> explicit Graph(vector<pair<Vertex,Vertex>> const & E) -> Graph<Vertex>;
template <typename Vertex> ostream & operator<<(ostream & s, Graph<Vertex> & g)
{
    return g.puts(s);
}

#endif

