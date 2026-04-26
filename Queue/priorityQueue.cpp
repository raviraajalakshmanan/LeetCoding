#include <iostream>
#include <queue>

using namespace std;

int main() {
  priority_queue<int> pq; // max heap
  pq.emplace(12);
  pq.emplace(89);
  pq.emplace(67);
  pq.emplace(671);
  pq.emplace(11);

  while (!pq.empty()) {
    cout << pq.top();
    pq.pop();
    cout << "\n";
  }
  // heap - talks about priority who should be in the front , which ever is greated will be in the
  // front. min heap
  auto cmp1 = [](int a, int b) {
    return a > b; // nemonic -> min heap - first > second
  };
  priority_queue<int, vector<int>, decltype(cmp1)> minHeap(cmp1);

  // max heap
  auto cmp2 = [](int a, int b) {
    return a < b; // nemonic -> max heap - first < second
  };
  priority_queue<int, vector<int>, decltype(cmp2)> maxHeap(cmp2);

  // sorting a < b  - means a comes first then b. ascending order.
}