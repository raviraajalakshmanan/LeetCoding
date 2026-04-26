#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void floydWarshallAlgorithm(int V, vector<vector<long>> &distance) {
  for (int via = 0; via < V; via++) {

    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {

        // important - do not make this check to skip if
        // if (via == i || via == j) continue; // theory this is good but does not help to find
        // negative cycle. below is conter example
        // vector<vector<long>> distance = {
        //     {0, -1},
        //     {0,  0}
        // };
        // 0 -> 1 = -1
        // 1 -> 0 =  0
        // 0 -> 1 -> 0 = -1
        // distance[0][0] becomes -1
        // distance[0][1] becomes -2
        // distance[1][0] becomes -1
        // distance[1][1] becomes -2  this never happens when we are skipping via node check for j
        // or i
        if (distance[i][via] == INT_MAX || distance[via][j] == INT_MAX)
          continue;
        long newDistance = distance[i][via] + distance[via][j];
        distance[i][j] = min(distance[i][j], newDistance);
      }
    }
  }
  // to same node we can reach less than 0 then there is negative cycle.
  for (int i = 0; i < V; i++) {
    if (distance[i][i] < 0)
      cout << "Negative cycle found" << endl;
  }
}

int main() {
  int V = 4;
  vector<vector<long>> distance = {
      {0, 2, INT_MAX, INT_MAX},
      {1, 0, 3, INT_MAX},
      {INT_MAX, INT_MAX, 0, INT_MAX},
      {3, 5, 4, 0},
  };
  floydWarshallAlgorithm(V, distance);
  for (auto i : distance) {
    for (auto j : i) {
      cout << j << '\t';
    }
    cout << '\n';
  }
  return 0;
}