#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
public:
  DisjointSet(int vertices) {
    this->parent.resize(vertices);
    this->rank.resize(vertices);
    for (int i = 0; i < vertices; i++) {
      parent[i] = i;
    }
  }

  int find(int node) {
    if (parent[node] == node)
      return node;
    return parent[node] = find(parent[node]);
  }

  void unionByRank(int U, int V) {
    int ultimateParentU = find(U);
    int ultimateParentV = find(V);

    if (ultimateParentU == ultimateParentV)
      return; // same component

    if (rank[ultimateParentU] < rank[ultimateParentV]) {
      parent[ultimateParentU] = ultimateParentV;
    } else if (rank[ultimateParentU] > rank[ultimateParentV]) {
      parent[ultimateParentV] = ultimateParentU;
    } else {
      parent[ultimateParentU] = ultimateParentV;
      rank[ultimateParentU]++;
    }
  }

private:
  vector<int> parent;
  vector<int> rank;
};
int main() {
  int V = 7;
  DisjointSet ds(7);
  ds.unionByRank(1, 2);
  ds.unionByRank(2, 3);
  ds.unionByRank(4, 5);
  ds.unionByRank(6, 7);
  ds.unionByRank(5, 6);
  if (ds.find(3) == ds.find(7)) {
    cout << "Same" << endl;
  } else {
    cout << "not same" << endl;
  }
  ds.unionByRank(3, 7);
  if (ds.find(3) == ds.find(7)) {
    cout << "Same" << endl;
  } else {
    cout << "not same";
  }
}

// time taken is inverse ackerman function 4Alpha x how many edges in graph we need to union it
