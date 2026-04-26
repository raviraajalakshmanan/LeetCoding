// Bellman ford helps in detecting negative cycle and it does not fix it
// Dijkstra cannot identify the negative cycle - we dont know TLE is happening due to negative cycle
// or the complexity of graph and system memory

#include <iostream>
#include <vector>

using namespace std;

// process all the edges - relax it for n-1 iteration where n is vertices in graph
// for sake of easy procesing every edge is considered

struct Edge {
  int u;
  int v;
  int weight;

  Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

vector<int> bellmanFordAlgorithm(int V, int source, vector<Edge> &edges) {
  vector<int> distance(V, 1e8);
  distance[source] = 0;

  for (int i = 0; i < V - 1; i++) {
    for (auto edge : edges) {
      auto [source, destination, weight] = edge;
      if (distance[source] != 1e8) {
        if (distance[destination] > distance[source] + weight) {
          distance[destination] = distance[source] + weight;
        }
      }
    }
  }
  // to detect negative edge cycle.
  for (int i = 0; i < 1; i++) {
    for (auto edge : edges) {
      auto [source, destination, weight] = edge;
      if (distance[source] != 1e8) {
        if (distance[destination] > distance[source] + weight) {
          return {-1};
        }
      }
    }
  }
  cout << "No negative edge cycle" << endl;
  return distance;
}

int main() {
  int V = 6;
  vector<Edge> edges = {Edge(3, 2, 6),  Edge(5, 3, 1),  Edge(0, 1, 5), Edge(1, 5, -3),
                        Edge(1, 2, -2), Edge(3, 4, -2), Edge(2, 4, 3)};

  auto vec = bellmanFordAlgorithm(V, 0, edges);

  for (int i = 0; i < vec.size(); i++) {
    cout << "Distance from 0 to " << i << " is " << vec[i] << endl;
  }
}