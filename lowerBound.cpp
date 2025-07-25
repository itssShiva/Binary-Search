#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> &nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 3, 5, 7, 9};
    int x;

    cout << "Enter the number to find lower bound: ";
    cin >> x;

    int index = sol.lowerBound(nums, x);
    
    if(index == nums.size()) {
        cout << "No element is greater than or equal to " << x << ". Lower bound index is " << index << " (end of array)." << endl;
    } else {
        cout << "Lower bound of " << x << " is at index " << index << " with value " << nums[index] << "." << endl;
    }

    return 0;
}
