#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> subarrays;


void createSubarrays(vector<int>& nums) {
    vector<int> subarray;
    for (int i =0; i<nums.size(); i++) {
        for (int j = i; j<nums.size(); j++) {
            subarray.clear();
            for(int k=i; k<=j; k++) {
                subarray.push_back(nums[k]);
            }
            subarrays.push_back(subarray);
        }
        
    }
}

void printSubarrays() {
    for (auto& subarr: subarrays) {
        cout << "[ " ;
        for (auto& item: subarr) {
            cout << item << " "; 
        }
        cout << "]" << endl;
    }
}

int main()
{
    vector<int> nums{89, -1, 7, 11};
    subarrays.clear();
    createSubarrays(nums);
    printSubarrays();
    return 0;
}