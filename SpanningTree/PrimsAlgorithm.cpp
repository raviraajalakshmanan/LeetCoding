#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int u;
  int v;
  int wt;
  Edge(int _u, int _v, int _wt) : u(_u), v(_v), wt(_wt) {}
};
vector<Edge> res;
struct NodeDistance {
  int node;
  int distance;
  NodeDistance(int _node, int _distance) : node(_node), distance(_distance) {}
};

int getMSTUsingPrimsAlgorithm(int source, int V, vector<vector<NodeDistance>> &adjList) {
  int sum = 0;
  vector<bool> visited(V, false);
  auto cmp = [](Edge a, Edge b) {
    if (a.wt == b.wt)
      return a.u > b.u;
    return a.wt > b.wt;
  };

  priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
  visited[source] = true;
  for (auto neighbours : adjList[source]) {
    pq.emplace(Edge(source, neighbours.node, neighbours.distance));
  }

  while (!pq.empty()) {
    auto [u, v, wt] = pq.top();
    pq.pop();
    if (visited[v])
      continue;

    sum += wt;
    visited[v] = true;
    res.emplace_back(Edge(u, v, wt));
    for (auto neighbours : adjList[v]) {
      if (!visited[neighbours.node])
        pq.emplace(Edge(v, neighbours.node, neighbours.distance));
    }
  }

  return sum;
}

int main() {
  int V = 5;
  vector<vector<NodeDistance>> adjList(V);
  adjList[0] = {{1, 2}, {2, 1}};
  adjList[1] = {{0, 2}, {2, 1}};
  adjList[2] = {{0, 1}, {1, 1}, {4, 2}, {3, 2}};
  adjList[3] = {{2, 2}, {4, 1}};
  adjList[4] = {{2, 2}, {3, 1}};
  int source = 0; // any node can be source

  cout << "Total cost connecting all vertices in graph "
       << getMSTUsingPrimsAlgorithm(source, V, adjList) << endl;
  for (auto edges : res) {
    cout << edges.u << '\t' << edges.v << endl;
  }

  return 0;
}