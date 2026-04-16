#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
// DFS based topological sort - never works for cycle detection because we need to maintaing the
// visting state so which inturn boils down to simple dfs

// BFS based topological sort
bool hasCycleBFS(const vector<vector<int>> &adjList, int numberOfVertices) {
  vector<int> indegree(numberOfVertices, 0);
  for (auto neighbours : adjList) {
    for (auto neighbour : neighbours) {
      indegree[neighbour]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < numberOfVertices; i++) {
    if (indegree[i] == 0)
      q.push(i);
  }

  int processed = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    processed++;
    for (auto neighbour : adjList[node]) {
      indegree[neighbour]--;
      if (indegree[neighbour] == 0)
        q.push(neighbour);
    }
  }

  return processed < numberOfVertices;
}

int main() {
  int vertices = 5;
  vector<vector<int>> adjList(vertices);
  adjList[0] = {2};
  adjList[1] = {2};
  adjList[2] = {0};
  adjList[3] = {4};

  if (hasCycleBFS(adjList, vertices)) {
    cout << "Cycle" << endl;
  } else
    cout << "No Cycle" << endl;
}