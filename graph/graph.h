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

template <typename Vertex, typename Edge> struct OrderedRetrievableAdjanceyList : map<Vertex, set<Edge>> {};
template <typename Vertex, typename Edge, template <typename, typename> typename BasicGraph = OrderedRetrievableAdjanceyList>
struct Graph : BasicGraph<Vertex, Edge>
{
    Graph(vector<pair<Vertex, Vertex>> const & edges)
    {
        for (auto const & e : edges) {
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
template <typename Vertex, typename Edge = Vertex> explicit Graph(vector<pair<Vertex, Vertex>> const & edges) -> Graph<Vertex, Edge>;
template <typename Vertex, typename Edge> ostream & operator<<(ostream & s, Graph<Vertex, Edge> & g)
{
    return g.puts(s);
}

#endif

