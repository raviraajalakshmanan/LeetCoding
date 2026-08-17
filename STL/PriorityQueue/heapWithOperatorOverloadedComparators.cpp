#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int marks;
    Student(string _name, int _marks): name(_name), marks(_marks) {}

    bool operator <(const Student& other) const {
        if (this->marks < other.marks) return true;
        return false;
    }
};

int main() {
    vector<Student> stList {
        Student("Ravi", 90),
        Student("Raj", 78),
        Student("Sam", 23)
    };

    priority_queue<Student> pq;
    for(auto& s: stList) {
        pq.push(s);
    }
    while(!pq.empty()) {
        auto s = pq.top();
        cout << s.name << "->" << s.marks << endl;
        pq.pop();
    }
    return 0;
}