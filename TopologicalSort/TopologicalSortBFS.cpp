#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> res;

void topologicalSort(int V, const vector<vector<int>> &adjList) {
  queue<int> q;
  vector<int> indegree(V, 0);

  // create indegree mapping
  for (auto list : adjList) {
    for (auto neighbour : list) {
      indegree[neighbour]++;
    }
  }

  // add the elements in to queue if indegree is 0
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    auto ele = q.front();
    res.emplace_back(ele);
    q.pop();
    for (auto i : adjList[ele]) {
      indegree[i]--;
      if (indegree[i] == 0)
        q.push(i);
    }
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
  for (auto ele : res)
    cout << ele << "\t";
}