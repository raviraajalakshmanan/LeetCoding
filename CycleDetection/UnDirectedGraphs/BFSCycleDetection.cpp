#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum class State { VISITED = 0, NOT_VISITED };

enum class Cycle { PRESENT = 0, NOT_PRESENT };

Cycle hasCycle(int node, int parent, const vector<vector<int>> &adjList, vector<State> &states) {
  queue<pair<int, int>> q;
  q.push({node, parent});
  states[node] = State::VISITED;

  while (!q.empty()) {
    auto [node, parent] = q.front();
    q.pop();

    for (auto neighbour : adjList[node]) {
      if (states[neighbour] == State::NOT_VISITED) {
        q.push({neighbour, node});
        states[neighbour] =
            State::VISITED; // very important to mark visited when inserting in queue in case
        // of inserting while poping causes double insertion / duplicate insertion
      } else if (neighbour != parent) { // by default it is assume to be VISITED else if
        return Cycle::PRESENT;
      }
    }
  }

  return Cycle::NOT_PRESENT;
}

string toString(Cycle val) {
  switch (val) {
  case Cycle::NOT_PRESENT:
    return "No Cycle";
  case Cycle::PRESENT:
    return "Cycle";
  }
}

int main() {
  int vertices = 5;
  vector<State> states(vertices, State::NOT_VISITED);
  vector<vector<int>> adjList(vertices);
  adjList[0] = {2};
  adjList[1] = {2};
  adjList[2] = {0, 1};
  adjList[3] = {4};
  adjList[4] = {3};
  //   0 - 2 3 - 4
  //     /
  //   1
  for (int vertex = 0; vertex < vertices; vertex++) {
    if (states[vertex] != State::VISITED) {
      if (Cycle::PRESENT == hasCycle(vertex, -1, adjList, states)) {
        cout << "cycle found";
        return 0;
      }
    }
  }
  cout << "Cycle Not found";
}
