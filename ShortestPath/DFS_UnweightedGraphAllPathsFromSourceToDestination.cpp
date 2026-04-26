#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paths;
vector<int> path;
vector<bool> visited;

// BackTracking Approach - helps finding all the paths
void shortestPathUsingDFS(int source, int destination, int node, vector<vector<int>> &adjList) {
  visited[node] = true;
  path.emplace_back(node);

  if (node == destination) {
    paths.push_back(path);
  } else {
    // explore
    for (auto neighbour : adjList[node]) {
      if (!visited[neighbour])
        shortestPathUsingDFS(source, destination, neighbour, adjList);
    }
  }

  path.pop_back();
  visited[node] = false;
}

int main() {
  int V = 6;
  vector<vector<int>> adj(V);

  adj[0] = {1, 2};
  adj[1] = {0, 3};
  adj[2] = {0, 3};
  adj[3] = {1, 2, 4};
  adj[4] = {3, 5};
  adj[5] = {4};

  int source = 0, destination = 5;
  visited.resize(V, false);

  shortestPathUsingDFS(source, destination, source, adj);

  // print all paths
  for (auto &p : paths) {
    for (int node : p)
      cout << node << " ";
    cout << endl;
  }

  return 0;
  return 0;
}