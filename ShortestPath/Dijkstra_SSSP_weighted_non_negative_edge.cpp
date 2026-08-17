#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int u;
  int v;
  int w;

  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

struct NodesToBeExplored {
  int node;
  int distanceToReachTheNode;

  bool operator>(const NodesToBeExplored &other) const {
    return distanceToReachTheNode > other.distanceToReachTheNode;
  }
};

vector<vector<pair<int, int>>> getAdjList(const int &n, const vector<Edge> &edges) {
  vector<vector<pair<int, int>>> adjList(n);

  for (auto &e : edges) {
    adjList[e.u].push_back({e.v, e.w});
  }

  return adjList;
}

int main() {
  int n = 4;

  vector<Edge> edges = {Edge(0, 1, 100), Edge(1, 3, 600), Edge(1, 2, 100), Edge(2, 0, 100),
                        Edge(2, 3, 200)};

  auto adjList = getAdjList(n, edges);

  int source = 0;

  vector<int> distance(n, numeric_limits<int>::max());
  distance[source] = 0;

  priority_queue<NodesToBeExplored, vector<NodesToBeExplored>, greater<NodesToBeExplored>> pq;

  pq.push({source, 0});

  while (!pq.empty()) {
    auto [_node, _distanceToReachTheNode] = pq.top();
    pq.pop();

    if (_distanceToReachTheNode > distance[_node]) {
      continue;
    }

    for (auto &adjNode : adjList[_node]) {
      auto [node, weight] = adjNode;

      int relaxedDistance = _distanceToReachTheNode + weight;

      if (relaxedDistance < distance[node]) {
        distance[node] = relaxedDistance;
        pq.push({node, relaxedDistance});
      }
    }
  }

  for (int i = 0; i < distance.size(); i++) {
    cout << "Node " << i << " -> " << distance[i] << endl;
  }
}