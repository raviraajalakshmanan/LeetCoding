#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
public:
  DisjointSet(int vertices) {
    parent.resize(vertices);
    size.resize(vertices);

    for (int i = 0; i < parent.size(); i++) {
      parent[i] = i;
    }
  }

  int find(int node) {
    if (parent[node] == node)
      return node;
    return parent[node] = find(parent[node]);
  }

  void unionBySize(int U, int V) {
    int ultimateParentU = find(U);
    int ultimateParentV = find(V);

    if (ultimateParentU == ultimateParentV)
      return;
    if (size[ultimateParentU] < size[ultimateParentV]) {
      parent[ultimateParentU] = ultimateParentV;
      size[ultimateParentV]++;
    } else {
      parent[ultimateParentV] = ultimateParentU;
      size[ultimateParentU]++;
    }
  }

private:
  vector<int> parent;
  vector<int> size;
};

int main() {
  int V = 7;
  DisjointSet ds(7);
  ds.unionBySize(1, 2);
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);
  if (ds.find(3) == ds.find(7)) {
    cout << "Same" << endl;
  } else {
    cout << "not same" << endl;
  }
  ds.unionBySize(3, 7);
  if (ds.find(3) == ds.find(7)) {
    cout << "Same" << endl;
  } else {
    cout << "not same";
  }
}