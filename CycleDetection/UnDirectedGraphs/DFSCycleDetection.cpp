#include <iostream>
#include <vector>

using namespace std;

enum class State { VISITED = 0, NOT_VISITED };
enum class Cycle { PRESENT = 0, NOT_PRESENT };

Cycle hasCycle(int node, int parent, const vector<vector<int>> &adjList, vector<State> &states) {
  states[node] = State::VISITED;
  for (auto neighbour : adjList[node]) {
    if (states[neighbour] == State::NOT_VISITED) {
      if (hasCycle(neighbour, node, adjList, states) == Cycle::PRESENT) { // short circuit and exit.
        return Cycle::PRESENT;
      }
    } else if (neighbour != parent) {
      return Cycle::PRESENT;
    }
  }

  return Cycle::NOT_PRESENT;
}

string toString(Cycle state) {
  switch (state) {
  case Cycle::NOT_PRESENT:
    return "No cycle";
  case Cycle::PRESENT:
    return "Cycle";
  }
}

int main() {
  int vertices = 5;
  vector<State> states(vertices, State::NOT_VISITED);
  vector<vector<int>> adjList(vertices);
  adjList[0] = {2, 1};
  adjList[1] = {2, 0};
  adjList[2] = {0, 1};
  adjList[3] = {4};
  adjList[4] = {3};
  // Graph G - containing 2 components
  // 0 - 1 3 - 4
  // | /
  // 2
  for (int vertex = 0; vertex < vertices; vertex++) {
    if (states[vertex] == State::NOT_VISITED) {
      if (hasCycle(vertex, -1, adjList, states) == Cycle::PRESENT) {
        cout << "Cycle Detected";
        return 0;
      }
    }
  }
  cout << "Cycle Not Detected" << endl;
  return 0;
}