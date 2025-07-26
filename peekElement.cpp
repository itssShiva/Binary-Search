#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n - 2;

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1; // Should never reach here if there's at least one peak
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    // Find and print the peak index
    int peakIndex = sol.findPeakElement(nums);

    cout << "Peak element is at index: " << peakIndex << endl;
    cout << "Peak element value is: " << nums[peakIndex] << endl;

    return 0;
}
