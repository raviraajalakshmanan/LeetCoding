#include <iostream>
#include <queue>

using namespace std;

int main() {
    auto cmp = [] (const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first < b.first) return true;
        return false;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp); 
    
    pq.push({10, 89});
    pq.push({78, 12});
    pq.push({43, 89});
    pq.push({33, 1});

    while(!pq.empty()) {
        cout << pq.top().first << " -> " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}