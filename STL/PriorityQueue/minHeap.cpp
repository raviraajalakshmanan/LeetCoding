#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(890);
  pq.push(12);
  pq.push(54);
  pq.push(5);
  pq.push(8900);

  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  return 0;
}