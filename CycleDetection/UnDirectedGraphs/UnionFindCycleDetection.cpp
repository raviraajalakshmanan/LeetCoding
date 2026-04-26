#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
public:
  DisjointSet() = default;
  DisjointSet(int vertexes) {
    this->parent.resize(vertexes);
    this->rank.resize(vertexes);

    for (int i = 0; i < vertexes; i++) {
      parent[i] = i;
    }
  }

  int find(int node) {
    if (parent[node] == node)
      return node;
    return parent[node] = find(parent[node]);
  }

  bool unionByRank(int U, int V) {
    int ultimateParentU = find(U);
    int ultimateParentV = find(V);

    if (ultimateParentU == ultimateParentV) {
      return true;
    }

    if (this->rank[ultimateParentU] > this->rank[ultimateParentV]) {
      parent[ultimateParentV] = ultimateParentU;
    } else if (this->rank[ultimateParentV] > this->rank[ultimateParentU]) {
      parent[ultimateParentU] = ultimateParentV;
    } else {
      parent[ultimateParentU] = ultimateParentV;
      rank[ultimateParentV]++;
    }
    return false;
  }

private:
  vector<int> parent;
  vector<int> rank;
};

int main() {
  //   int V = 5;
  //   vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  //   int V = 3;
  //   vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}};
  //   int V = 5;
  //   vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1}};
  //   int V = 6;
  //   vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {3, 4}};
  int V = 6;
  vector<pair<int, int>> edges = {{0, 1},
                                  {1, 2},
                                  {2, 0}, // cycle here
                                  {3, 4}};
  DisjointSet ds(V);
  for (auto &edge : edges) {
    if (ds.unionByRank(edge.first, edge.second)) {
      cout << "cycle identified" << endl;
      return 0;
    }
  }
  cout << "No Cycle" << endl;
  return 0;
}