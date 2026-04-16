#include <iostream>
#include <vector>

using namespace std;

enum class State { VISITED = 0, VISITING, NOT_VISITED };
enum class Cycle { PRESENT = 0, NOT_PRESENT };

Cycle hasCycle(int node, int parent, const vector<vector<int>> &adjList, vector<State> &states) {
  states[node] = State::VISITING;
  for (auto neighbour : adjList[node]) {
    if (states[neighbour] == State::NOT_VISITED) {
      if (hasCycle(neighbour, node, adjList, states) == Cycle::PRESENT) { // short circuit and exit.
        return Cycle::PRESENT;
      }
    } else if (states[neighbour] == State::VISITING) {
      return Cycle::PRESENT;
    }
  }
  states[node] = State::VISITED;
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
  int vertices = 3;
  vector<State> states(vertices, State::NOT_VISITED);
  vector<vector<int>> adjList(vertices);
  adjList[0] = {2};
  adjList[1] = {2};
  adjList[2] = {};
  // Graph G
  // 0  1
  // | /
  // 2

  cout << toString(hasCycle(0, -1, adjList, states));
}