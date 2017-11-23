#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

template <typename Vertex, typename Edge = Vertex> using BasicGraph = map<Vertex, set<Edge>>;
struct Graph : BasicGraph<string> {
    enum class EdgeSymmetry { Directed, Undirected };
    Graph(vector<pair<string,string>> const E, EdgeSymmetry symmetry = EdgeSymmetry::Undirected)
    {
        for (auto const & e : E) {
            operator[](e.first).emplace(e.second);
            if (symmetry == EdgeSymmetry::Undirected) {
                operator[](e.second).emplace(e.first);
            }
        }
    }
    ostream & puts(ostream & s)
    {
        for (auto const & v : *this) {
            s << v.first << ": ";
            for (auto const & w: v.second) {
                s << w << " ";
            }
            s << "\n";
        }
        return s;
    }
};
ostream & operator<<(ostream & s, Graph & g)
{
    return g.puts(s);
}

void bfs(Graph & g, string u)
{
    if (g.find(u) == g.end()) return;
    else cout << "bfs: ";

    enum class status {discovered, expending, processed};
    struct state {
        status status;
        string parent;
        unsigned distance = 0;
    };
    map<string, state> states;
    states[u] = {status::discovered, "0", 0};

    queue<string> q;
    q.push(u);
    while (!q.empty()) {
        string v = q.front();
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

void ucs(Graph & g, string u)
{
    if (g.find(u) == g.end()) return;
    else cout << "ucs: ";

    enum class status {discovered, expending, processed};
    struct state {
        status status;
        string parent;
        unsigned distance = 0;
    };
    map<string, state> states;
    states[u] = {status::discovered, "0", 0};

    priority_queue<string> q;
    q.push(u);
    while (!q.empty()) {
        string v = q.top();
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

void dfs(Graph & g, string u)
{
    if (g.find(u) == g.end()) return;
    else cout << "dfs: ";

    enum class status {discovered, expending, processed};
    struct state {
        status status;
        string parent;
        unsigned distance = 0;
    };
    map<string, state> states;
    states[u] = {status::discovered, "0", 0};

    stack<string> s;
    s.push(u);
    while (!s.empty()) {
        string v = s.top();
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

void DFS(Graph & g, string v)
{
    if (g.find(v) == g.end()) return;

    enum class status {discovered, expending, processed};
    struct state {
        status status;
        string parent;
        unsigned distance = 0;
        unsigned enter = 0;
        unsigned leave = 0;
    };
    static map<string, state> states;
    static unsigned time = 0;

    if (states.find(v) == states.end()) {
        states[v] = {status::discovered, "0", 0};
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

int main()
{
    vector<pair<string,string>> TADM2_Figure_5_9_Figure_5_10 = {
        {"1","6"},
        {"1","2"},{"1","5"},
        {"2","5"},
        {"2","3"},{"5","4"},
        {"3","4"}
    };

    auto const & E = TADM2_Figure_5_9_Figure_5_10;
    Graph g(E);
    cout << g;
    bfs(g, "1");
    cout << endl;
    ucs(g, "1");
    cout << endl;
    dfs(g, "1");
    cout << endl;
    DFS(g, "1");
    cout << endl;
}
