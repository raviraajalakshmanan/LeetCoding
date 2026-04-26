#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> res;
int sum = 0;

struct Edge {
  int u;
  int v;
  int wt;
  Edge(int _u, int _v, int _wt) : u(_u), v(_v), wt(_wt) {}
};

struct NodeDistance {
  int node;
  int distance;
  NodeDistance(int _node, int _distance) : node(_node), distance(_distance) {}
};

class DisjointSet {
public:
  DisjointSet(int V) {
    this->parent.resize(V);
    this->rank.resize(V);

    for (int i = 0; i < V; i++) {
      parent[i] = i;
    }
  }

  int find(int node) {
    if (parent[node] == node)
      return node;
    return parent[node] = find(parent[node]);
  }

  bool unionByRank(int U, int V, int wt) {
    int ulitmateParentU = find(U);
    int ulitmateParentV = find(V);
    if (ulitmateParentV == ulitmateParentU) {
      // cout << "Same Component";
      return false;
    }

    if (rank[ulitmateParentU] > rank[ulitmateParentV]) {
      parent[ulitmateParentU] = ulitmateParentV;
    } else if (rank[ulitmateParentU] < rank[ulitmateParentV]) {
      parent[ulitmateParentV] = ulitmateParentU;
    } else {
      parent[ulitmateParentV] = ulitmateParentU;
      rank[ulitmateParentV]++;
    }
    res.push_back({U, V});
    sum += wt;
    return true;
  }

private:
  vector<int> parent;
  vector<int> rank;
};

vector<Edge> createEdges(const vector<vector<NodeDistance>> &adjList, int V) {
  vector<Edge> res;
  for (int i = 0; i < V; i++) {
    for (auto neighbour : adjList[i]) {
      res.emplace_back(i, neighbour.node, neighbour.distance);
    }
  }
  return res;
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

  DisjointSet ds(V);

  vector<Edge> input = createEdges(adjList, V);

  auto cmp = [](Edge a, Edge b) {
    if (a.wt == b.wt)
      return a.u < b.u;
    return a.wt < b.wt;
  };

  sort(input.begin(), input.end(), cmp);

  for (auto edge : input) {
    ds.unionByRank(edge.u, edge.v, edge.wt);
  }

  for (auto edges : res) {
    cout << edges[0] << '\t' << edges[1] << endl;
  }

  cout << sum << endl;
}

// important to node that sorting comparator a < b sorts ascending but in PQ a < b is max heap.