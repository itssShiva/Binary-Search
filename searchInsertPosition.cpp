#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target)  {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= target) {
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
    vector<int> nums = {1, 3, 5, 6};
    int target;

    cout << "Enter the target to insert: ";
    cin >> target;

    int index = sol.searchInsert(nums, target);
    cout << "Target should be at index: " << index << endl;

    return 0;
}
