#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        int low = 1;
        int high = n - 2;

        // Boundary cases
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // Should not reach here for valid input
    }
};

int main() {
    Solution sol;

    // Test input
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};

    // Function call
    int result = sol.singleNonDuplicate(nums);

    // Output
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}
