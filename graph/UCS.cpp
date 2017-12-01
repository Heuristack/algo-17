#include "graph.h"
#include "graph-data.h"
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iostream>
using namespace std;

template <typename Vertex, typename Edge = Vertex, typename Graph = map<Vertex, set<Edge>>>
void ucs(Graph & g, Vertex u)
{
    if (g.find(u) == g.end()) return;
    else cout << "ucs: ";

    enum class status {discovered, expending, processed};
    struct state {
        status status;
        Vertex parent;
        unsigned distance = 0;
    };
    map<Vertex, state> states;
    states[u] = {status::discovered, {}, {}};

    priority_queue<Vertex> q;
    q.push(u);
    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        states[v].status = status::expending;
        for (auto const & w : g[v]) {

            if (states.find(w) == states.end()) {
                states[w] = {status::discovered, v, states[v].distance+1};
                q.push(w);
            }

        }
        cout << "[" << v << "<-" << states[v].parent << ":" << states[v].distance << "]";
        states[v].status = status::processed;
    }
}

int main()
{
    auto const & E = TADM2_Figure_5_9_Figure_5_10;
    Graph g(E);
    ucs(g, 1);
    cout << endl;
}

