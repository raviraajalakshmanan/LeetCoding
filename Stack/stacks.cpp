#include <iostream>
#include <stack>

using namespace std;

int main() {
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(43);
  st.push(4);

  st.size();  // gets the size of stack
  st.empty(); // check for emptiness
  st.top();   // returns top
  st.pop();   // removes the top
  return 0;
}
