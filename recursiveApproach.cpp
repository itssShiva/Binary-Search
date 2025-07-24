#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target,int low,int high) {
       
        if(low>high)return -1;
        int mid=(low+high)/2;
        if(nums[mid]==target)return mid;
        else if(target>nums[mid])return search(nums,target,mid+1,high);
        return search(nums,target,low,mid-1);
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int low=0;
    int high=(nums.size())-1;

    int result = sol.search(nums, target,low,high);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
