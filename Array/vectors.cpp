#include <iostream>
#include <vector>

using namespace std;

int main() {
  // create an vector;
  vector<int> v;

  // create vector of fixed size;
  vector<int> v_resevered(10);
  for (auto item : v_resevered)
    cout << item << "\t"; // prints 0 default value when int type is used. nullptr in case of object
                          // 0.0 / false/ '\0'
  cout << endl;

  // reserve array with default value 90.
  vector<int> v_reserved_with_val(10, 90);
  for (auto item : v_reserved_with_val)
    cout << item << "\t";
  cout << endl;
}