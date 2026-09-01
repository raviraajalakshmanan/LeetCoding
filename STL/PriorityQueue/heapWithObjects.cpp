#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Student {
  string name;
  int marks;
  Student(string _name, int _marks) : name(_name), marks(_marks) {}
};

int main() {
  vector<Student> stList{Student("Ravi", 90), Student("Raj", 78), Student("Sam", 23)};
  auto cmp = [](const Student &a, const Student &b) { return a.marks < b.marks; };
  priority_queue<Student, vector<Student>, decltype(cmp)> pq(cmp);
  for (auto &s : stList) {
    pq.push(s);
  }
  while (!pq.empty()) {
    auto s = pq.top();
    cout << s.name << "->" << s.marks << endl;
    pq.pop();
  }
  return 0;
}