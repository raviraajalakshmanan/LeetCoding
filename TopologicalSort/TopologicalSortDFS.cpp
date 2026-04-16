#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>> &adjList, vector<bool> &visited, stack<int> &st) {
  visited[node] = true;
  for (auto neighbour : adjList[node]) {
    if (visited[neighbour] == false) {
      dfs(neighbour, adjList, visited, st);
    }
  }
  st.push(node);
}

void topologicalSort(int V, const vector<vector<int>> &adjList) {
  vector<bool> visited(V, false);
  stack<int> st;
  // start with any node
  for (int node = 0; node < V; node++) {
    if (visited[node] == false) {
      dfs(node, adjList, visited, st);
    }
  }

  while (!st.empty()) {
    cout << st.top() << "\t";
    st.pop();
  }
}

int main() {
  int V = 6;
  vector<vector<int>> adjList(V);

  adjList[5] = {2, 0};
  adjList[4] = {0, 1};
  adjList[2] = {3};
  adjList[3] = {1};

  topologicalSort(V, adjList);
}