#include "graph.h"
#include "graph-data.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>
using namespace std;

template <typename Vertex, typename Edge = Vertex, typename Graph = map<Vertex, set<Edge>>>
void dfs(Graph & g, Vertex u)
{
    if (g.find(u) == g.end()) return;
    else cout << "dfs: ";

    enum class status {discovered, expending, processed};
    struct state {
        status status;
        Vertex parent;
        unsigned distance = 0;
    };
    map<Vertex, state> states;
    states[u] = {status::discovered, {}, {}};

    stack<Vertex> s;
    s.push(u);
    while (!s.empty()) {
        auto v = s.top();
        s.pop();
        states[v].status = status::expending;
        for (auto const & w : g[v]) {
            if (states.find(w) == states.end()) {
                states[w] = {status::discovered, v, states[v].distance+1};
                s.push(w);
            }

        }
        cout << "[" << v << "<-" << states[v].parent << ":" << states[v].distance << "]";
        states[v].status = status::processed;
    }
}

template <typename Vertex, typename Edge = Vertex, typename Graph = map<Vertex, set<Edge>>>
void DFS(Graph & g, Vertex v)
{
    if (g.find(v) == g.end()) return;

    enum class status {discovered, expending, processed};
    struct state {
        status status;
        Vertex parent;
        unsigned distance = 0;
        unsigned enter = 0;
        unsigned leave = 0;
    };
    static map<Vertex, state> states;
    static unsigned time = 0;

    if (states.find(v) == states.end()) {
        states[v] = {status::discovered, {}, {}};
        cout << "DFS: ";
    }

    states[v].status = status::expending;
    states[v].enter = time++; cout << "(";
    for (auto const & w : g[v]) {
        if (states.find(w) == states.end()) {
            states[w] = {status::discovered, v, states[v].distance+1};
            DFS(g, w);
        }
    }
    cout << "[" << v << "<-" << states[v].parent << ":" << states[v].distance << "]";
    states[v].leave = time++; cout << ")";
    states[v].status = status::processed;
}

template <typename V, typename E> using HashedRetrievableAdjacencyList = unordered_map<V, unordered_set<E>>;
int main()
{
    auto const & E = TADM2::Figure_5_9;
    Graph g(E);
    dfs(g, 1);
    cout << endl;

    Graph<int, int, int, HashedRetrievableAdjacencyList> G(E);
    DFS(G, 1);
    cout << endl;
}

