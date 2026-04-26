#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> res;

void shortestPathFinder(vector<int> &parent, int source, int destination) {
  if (parent[destination] == -1) {
    res.push_back(source);
    cout << "appended all nodes in path" << endl;
    return;
  }
  res.push_back(destination);
  shortestPathFinder(parent, source, parent[destination]);
}

vector<int> shortestPathUsingBFS(int source, int destination, int V, vector<vector<int>> &adjList) {
  vector<int> parent(V, -1);
  vector<int> distance(V, 0);
  vector<bool> visited(V, false);

  queue<int> q;

  q.push(source);
  visited[source] = true;
  distance[source] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int neighbours : adjList[node]) {
      if (!visited[neighbours]) {
        visited[neighbours] = true;
        parent[neighbours] = node;
        distance[neighbours] = distance[node] + 1;

        q.push(neighbours);
      }

      if (neighbours == destination)
        break;
    }
  }
  // important - if not path found then return empty list
  if (!visited[destination])
    return {};
  shortestPathFinder(parent, source, destination);
  reverse(res.begin(), res.end());
  return res;
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

  int source = 0, target = 5;

  vector<int> path = shortestPathUsingBFS(source, target, V, adj);

  if (path.empty()) {
    cout << "No path found\n";
  } else {
    cout << "Shortest path: ";
    for (int node : path)
      cout << node << " ";
    cout << endl;
  }
  return 0;
}
