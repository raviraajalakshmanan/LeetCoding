#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int node;
  int weight;
  Node(int _node, int _weight) : node(_node), weight(_weight) {}
};

struct NodeDistance {
  int node;
  int distance;
  NodeDistance(int _node, int _distance) : node(_node), distance(_distance) {}
};

void dijkstraAlgorithm(int source, int V, vector<vector<Node>> &adjList) {
  auto cmp = [](NodeDistance a, NodeDistance b) {
    if (a.distance == b.distance)
      return a.node > b.node;
    return a.distance > b.distance;
  };
  priority_queue<NodeDistance, vector<NodeDistance>, decltype(cmp)> pq(cmp);
  vector<int> distance(V, INT_MAX);
  distance[source] = 0;
  pq.emplace(NodeDistance(source, distance[source]));

  while (!pq.empty()) {
    auto [node, nodes_distance] = pq.top();
    pq.pop();

    for (auto neighbours : adjList[node]) {
      int new_distance = nodes_distance + neighbours.weight;
      if (new_distance < distance[neighbours.node]) { // relaxation
        distance[neighbours.node] = new_distance;
        pq.emplace(NodeDistance(neighbours.node, new_distance));
      }
    }
  }

  for (int i = 0; i < V; i++) {
    cout << "Distance to " << i << " node is  :" << distance[i] << endl;
  }
}

int main() {
  // weighted graph so 2d array is used

  int V = 6;
  vector<vector<Node>> adjList(V);
  adjList[0] = {Node(1, 4), Node(2, 4)};
  adjList[1] = {Node(0, 4), Node(2, 2)};
  adjList[2] = {Node(0, 4), Node(1, 2), Node(3, 3), Node(4, 1), Node(5, 6)};
  adjList[3] = {Node(2, 3), Node(5, 2)};
  adjList[4] = {Node(2, 1), Node(5, 3)};
  adjList[5] = {Node(2, 6), Node(3, 2), Node(4, 3)};
  int source = 0; // this is imp - we are finding shortest path from source node 0
  dijkstraAlgorithm(0, V, adjList);
}