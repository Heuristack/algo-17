***

Concepts
--------
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
---------------
Proper graph modeling (how to implement the graph data structure) is the key to making efficient use of graph algorithms, take the adjacency list for example, each item in which could be a vertex or an edge totegher with some auxiliary information like weight, direction, etc. Whether only out-edges or both out-edges and in-edges are stored for further retrieval depends on operations required by algorithms.

#### Graph Representations
* Adjacency Matrix
* **Adjacency List**
* **Edge List**

#### Graph Dimensions
* **Directed vs Undirected**
* **Weighted vs Unweighted**
* Cyclic vs Acyclic
* Dense vs Sparse
* Simple vs Non-simple
* Explicit vs Implicit
* Labeled vs Unlabeled
* Embedded vs Topological


Algorithms
----------

### Search: BFS - DFS
The essence of searching is to **follow up one option now and put the others aside for later** in an **open list** representing the searching **frontier**. While algorithms that **forget their history are doomed to repeat it**, to avoid which, visited vertexes or edges are kept in a **closed list** representing the **explored set** that differentiates **graph search** from **tree search**.

#### Frontier Data Structures
* Stack
* Queue
* Priority Queue

#### Edge Classification
* Tree Edge
* Forward Edge
* Back Edge
* Cross Edge

#### BFS: Breadth-First Search and Properties
* Frontier: Queue
* Predecessor Subgraph: BFS Tree
* Visit Order: Read = Read from left to right line by line.
* Edge Classification: Tree, Cross Edge (Undirected); Tree, Back, Cross Edge (Directed)
* Shortest-Path (Unweighted):

#### DFS: Depth-First Search and Properties
* Frontier: Stack
* Predecessor Subgraph: DFS Tree
* Visit Order: Walk (Around: before or after) = Go along to the deepest and come back along the same way. PreOrder, PostOrder and Reverse PostOrder.
* Edge Classification: Tree, Back Edge (Undirected);
* Parenthesis Structure (Directed or Undirected):
* White-Path (Directed or Undirected):

#### Event Visitors
* Initialize Vertices (optional)
* Start Vertex (optional)
* Discover Vertex
* Examine Edge
* Tree Edge
* Back Edge
* Forward or Cross Edge
* Cycle Edge
* Finish Vertex
* Edge Relaxed
* Edge Minimized

#### Applications
* Reachability: Path Finding
* Connectivity: CC (Connected Component) and SCC (Strongly Connected Component)
* Cyclicity: Acyclic = No back edge in DFS Tree
* Topological Sort: DAG = Topological Order Exists. DFS Reverse PostOrder = Topological Order.


### MST: Minimum Spanning Trees (Undirected, Weighted)

**Concepts**

* Cut: A `cut = (S, V - S)` is a partition of `V`.
* Cross: An edge `(u, v)` crosses the cut if one of `{u, v}` in `S` while the other in `V - S`.
* Respect: A cut respects a set of edges `A`, if no edge in `A` crosses the cut.
* Light Edge: an edge crosses the cut with minimum weight

**Generic Minimum Spanning Tree Algorithm:** Grow the MST one edge a time

* Manage a set of edges A and
* Maintain the loop Invariant: prior to each iteration, A is a subset of some minimum spanning tree
* Determine an edge (u, v) that can be added to A without violating the invariant, at each iteration
* Until A forms a minimum spanning tree

#### Kruskal's Algorithm

#### Prim's Algorithm


### SSSP: Single Source Shortest Paths (Directed, Weighted)
**Relaxation:** relax shortest-path estimate according to the triangle-inequality (reduce the estimated path weight)

**Properties**

* Optimal Substructure: subpaths of a shortest paths are shortest paths
* Triangle Inequallity: For edge `(u, v)` with weight `w(u, v)`, shortest path `p(s, v) <= p(s, u) + w(u, v)`
* Upper-Bound:
* No-Path: If `p(s, t)` is infinity, there is no shortest path from `s` to `t`
* Convergence:
* Path-Relaxation:
* Predecessor-Subgraph:

**Bellman-Ford Algorithm:** 

**Dijkstra's Algorithm:** Greedily choose the edge which yields a shortest path at present using priority queue as frontier;

***
