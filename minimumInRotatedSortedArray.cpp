#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

// Your provided Solution class
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If current segment is sorted
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example rotated sorted array (without duplicates)
    vector<int> nums = {4, 5, 6, 7,  1, 2};

    int minimum = sol.findMin(nums);

    cout << "Minimum element in the array: " << minimum << endl;

    return 0;
}
