***

Concepts
========
**Graph: vertex - edge** |
symmetry: **undirected - directed** |
edge: in - out |
degree: in - out |
weight: **unweighted - weighted** |
**adjacency** |
incidence: on - from - to |
reachability: path - subpath - simple path |
cyclicity: cyclic - acyclic - cycle |
connectivity: isolated - connected - strongly connected - **connected component** |
complete graph - bipartite graph - hypergraph |
free tree - rooted tree |
**ordered tree - positional tree** |
node: internal - external |
root - leaf |
ancestor - descendant | 
parent - child - sibling |
**depth - height** |

#### Free Tree Properties
Let `G = (V, E)` be an **undirected graph**, the following statements are equivalent

* `G` is a free tree = any two vertices in `G` are connected by a unique simple path
* `G` is connected but if any edge is removed from `E` the resulting graph is disconnected
* `G` is connected and `|E| = |V| - 1`
* `G` is acyclic and `|E| = |V| - 1`
* `G` is acyclic but if any edge is added to `E` the resulting graph contains a cycle


Data Structures
===============
Proper graph modeling (how to implement the graph data structure) is the key to making efficient use of graph algorithms, take the adjacency list for example, each item in which could be a vertex or an edge totegher with some auxiliary information like weight, direction, etc. Whether only out-edges or both out-edges and in-edges are stored for further retrieval depends on operations required by algorithms.

**Graph Representations:** 
**`adjacency_matrix` `adjacency_list` `edge_list`**

**Graph Dimensions:** 
**`directed-undirected` `weighted-unweighted` `cyclic-acyclic`**


Algorithms
==========
**`BDPKBD`**

### Search: `BFS` `DFS`
**The essence of searching** 
is to **follow up one option now and put the others aside for later** in an **open list** representing the searching **frontier**. While algorithms that **forget their history are doomed to repeat it**, to avoid which, visited vertexes or edges are kept in a **closed list** representing the **explored set** that differentiates **graph search** from **tree search**.

**Frontier Data Structures:**
**`stack` `queue` `priority_queue`**

**Edge Classification:**
**`tree edge` `forward edge` `back edge` `cross edge`**

#### Breadth-First Search `BFS`
* Frontier: Queue
* Predecessor Subgraph: BFS Tree
* Visit Order: **Read:** Read from left to right line by line.
* Edge Classification: Tree, Cross Edge (Undirected); Tree, Back, Cross Edge (Directed)
* Shortest-Path (Unweighted):

#### Depth-First Search `DFS`
* Frontier: Stack
* Predecessor Subgraph: DFS Tree
* Visit Order: **Walk (Around: before or after):** Go along to the deepest and come back along the same way. **`PRE_ORDER` `POST_ORDER`**
* Edge Classification: Tree, Back Edge (Undirected);
* Parenthesis Structure (Directed or Undirected):
* White-Path (Directed or Undirected):

#### Searching Applications
* **Reachability**: **`PathFind`**
* **Connectivity**: **`ConnectedComponent` `StronglyConnectedComponent`**
* **Cyclicity**: Acyclic = No back edge in DFS Tree
* **Topological Sort**: DAG = Topological Order Exists. DFS Reverse PostOrder = Topological Order.


### Minimum Spanning Trees `MST`
**`Undirected`**
**`Weighted`**

**cut** - a binary partition of the vertex set.
**cross** - an edge connecting the 2 subsets of the binary partition of the cut.
**respect** - a cut respects an edge set if no edge in the set cross the cut.
**light** - the minimum weighted edge crosses the cut.

**Generic MST:** 
Choose the minimum safe edge **greedily** then add it to edge subset of the minimum spanning tree one-by-one.

* maintain an edge set as a subset of the minimum spanning tree
* select an safe edge and add it into the set at each iteration
* until all vertices are contained by the edge set


**Prim's Algorithm:**

**Kruskal's Algorithm:**



### Single Source Shortest Paths `SSSP`
**`Directed`** **`Weighted`**

**relaxation:** relax shortest-path estimate according to the triangle-inequality (reduce the estimated path weight).

**Properties**

* Optimal Substructure: subpaths of a shortest paths are shortest paths
* Triangle Inequallity: For edge `(u,v)` with weight `w(u,v)`, shortest path `p(s,v) <= p(s,u) + w(u,v)`
* Upper-Bound:
* No-Path: If `p(s,t)` is infinity, there is no shortest path from `s` to `t`
* Convergence:
* Path-Relaxation:
* Predecessor-Subgraph:

**Bellman-Ford Algorithm:** 

**Dijkstra's Algorithm:** Greedily choose the edge which yields a shortest path using priority queue as frontier.


### Events
* **Vertex Exploration:** **`discover_vertex` `finish_vertex`**
* **Edge Exploration:** **`examine_edge` `cycle_edge`**
* **Edge Classification:** **`tree_edge` `forward_edge` `cross_edge` `back_edge`**
* **Edge Relaxation:** **`edge_relaxed` `edge_minimized`**

***
