# NiralCPP

A focused reference implementation of graph algorithms and tree traversals in modern C++. Each algorithm lives in its own file with a working `main` driver — no external dependencies, no build system required.

---

## Contents

### Shortest Path

| Algorithm | File | Use case |
|---|---|---|
| BFS | [BFS_UnweightedGraph.cpp](ShortestPath/BFS_UnweightedGraph.cpp) | Unweighted graphs |
| DFS (all paths) | [DFS_UnweightedGraphAllPathsFromSourceToDestination.cpp](ShortestPath/DFS_UnweightedGraphAllPathsFromSourceToDestination.cpp) | Enumerate all source-to-destination paths |
| Dijkstra | [Dijkstra_SSSP_weighted_non_negative_edge.cpp](ShortestPath/Dijkstra_SSSP_weighted_non_negative_edge.cpp) | Weighted graphs, no negative edges |
| Bellman-Ford | [Bellman_Ford_SSSP_algorithm.cpp](ShortestPath/Bellman_Ford_SSSP_algorithm.cpp) | Negative edges, negative cycle detection |
| Floyd-Warshall | [FloydWarshallAlgorithm.cpp](ShortestPath/FloydWarshallAlgorithm.cpp) | All-pairs shortest path, negative cycle detection |

### Spanning Tree

| Algorithm | File |
|---|---|
| Kruskal | [KruskalAlgorithm.cpp](SpanningTree/KruskalAlgorithm.cpp) |
| Prim | [PrimsAlgorithm.cpp](SpanningTree/PrimsAlgorithm.cpp) |

### Cycle Detection

**Directed graphs**

| Technique | File |
|---|---|
| BFS | [CycleDetection/DirectedGraphs/BFSCycleDetection.cpp](CycleDetection/DirectedGraphs/BFSCycleDetection.cpp) |
| DFS | [CycleDetection/DirectedGraphs/DFSCycleDetection.cpp](CycleDetection/DirectedGraphs/DFSCycleDetection.cpp) |
| Topological sort | [CycleDetection/DirectedGraphs/TopologicalSortCycleDetection.cpp](CycleDetection/DirectedGraphs/TopologicalSortCycleDetection.cpp) |
| Union-Find | [CycleDetection/DirectedGraphs/UnionFindCycleDetection.cpp](CycleDetection/DirectedGraphs/UnionFindCycleDetection.cpp) |

**Undirected graphs**

| Technique | File |
|---|---|
| BFS | [CycleDetection/UnDirectedGraphs/BFSCycleDetection.cpp](CycleDetection/UnDirectedGraphs/BFSCycleDetection.cpp) |
| DFS | [CycleDetection/UnDirectedGraphs/DFSCycleDetection.cpp](CycleDetection/UnDirectedGraphs/DFSCycleDetection.cpp) |
| Topological sort | [CycleDetection/UnDirectedGraphs/TopologicalSortCycleDetection.cpp](CycleDetection/UnDirectedGraphs/TopologicalSortCycleDetection.cpp) |
| Union-Find | [CycleDetection/UnDirectedGraphs/UnionFindCycleDetection.cpp](CycleDetection/UnDirectedGraphs/UnionFindCycleDetection.cpp) |

### Topological Sort

| Algorithm | File |
|---|---|
| BFS (Kahn's) | [TopologicalSort/TopologicalSortBFS.cpp](TopologicalSort/TopologicalSortBFS.cpp) |
| DFS | [TopologicalSort/TopologicalSortDFS.cpp](TopologicalSort/TopologicalSortDFS.cpp) |

### Union-Find (Disjoint Set)

| Variant | File |
|---|---|
| Union by rank | [UnionFind/UnionByRank.cpp](UnionFind/UnionByRank.cpp) |
| Union by size | [UnionFind/UnionBySize.cpp](UnionFind/UnionBySize.cpp) |

### Binary Tree Traversal

Each traversal provides both a recursive and an iterative implementation behind a common strategy interface.

| Traversal | File |
|---|---|
| Inorder | [BinaryTreeInorderTraversal/Solution.cpp](BinaryTreeInorderTraversal/Solution.cpp) |
| Preorder | [BinaryTreePreorderTraversal/Solution.cpp](BinaryTreePreorderTraversal/Solution.cpp) |
| Postorder | [BinaryTreePostorderTraversal/Solution.cpp](BinaryTreePostorderTraversal/Solution.cpp) |

---

## Building

Any file compiles standalone with a C++17-capable compiler.

```sh
g++ -std=c++17 -O2 ShortestPath/Dijkstra_SSSP_weighted_non_negative_edge.cpp -o dijkstra
./dijkstra
```

Replace the path with whichever file you want to run.

## Formatting

The project uses [clang-format](https://clang.llvm.org/docs/ClangFormat.html) with LLVM style (2-space indent, 100-column limit). A helper script is provided:

```sh
./scripts/format.sh
```

## License

[GPL-3.0](LICENSE)
