#include <iostream>
#include <queue>

using namespace std;

int main() {
    auto cmp = [] (const vector<int>& a, const vector<int>& b) {
        if (a[0] < b[0]) return true;
        return false;
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp); 
    
    pq.push({10, 89});
    pq.push({78, 12});
    pq.push({43, 89});
    pq.push({33, 1});

    while(!pq.empty()) {
        cout << pq.top()[0] << " -> " << pq.top()[1] << endl;
        pq.pop();
    }
    return 0;
}