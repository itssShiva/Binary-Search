#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// Your provided Solution class
class Solution {
public:
    int findKRotation(vector<int>& nums) {
        int low = 0;
        int index = -1;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;
            // If the current segment is sorted
            if (nums[low] <= nums[high]) {
                if(nums[low]<ans){
                     ans = min(ans, nums[low]);
                index = low;
                }
               
                break;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] < ans) {
                    ans = nums[low];
                    index = low;
                }
                low = mid + 1;
            } else {
                if (nums[mid] < ans) {
                    ans = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }

        return index;
    }
};

int main() {
    Solution sol;

    // Example rotated sorted array
    vector<int> nums = {15, 18, 2, 3, 6, 12};

    int k = sol.findKRotation(nums);

    cout << "The array is rotated " << k << " times." << endl;

    return 0;
}
