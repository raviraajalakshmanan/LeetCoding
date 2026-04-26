#include <iostream>
#include <queue>

using namespace std;

int main() {
  queue<int> q;
  q.push(10);
  q.push(123);
  q.push(56);

  cout << q.front() << endl;
  cout << q.back() << endl;

  cout << q.size() << endl;
  cout << q.empty() << endl;
  queue<int> q1;
  q.swap(q1); // swap contents of queue
  return 0;
}