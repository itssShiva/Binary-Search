#include <iostream>
#include <vector>
#include <algorithm> // for max_element
#include <numeric>   // for accumulate
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& nums, int mid, int n) {
        int stu = 1;
        int pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + nums[i] <= mid) {
                pagesStudent += nums[i];
            } else {
                stu++;
                pagesStudent = nums[i];
            }
        }
        return stu;
    }

    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        if (m > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int noOfStu = countStudents(nums, mid, n);
            if (noOfStu > m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }

    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, k);
    }
};

int main() {
    // Example: Split [7, 2, 5, 10, 8] into k=2 subarrays (LeetCode 410)
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    Solution sol;
    int result = sol.splitArray(nums, k);

    cout << "Minimum largest sum of subarrays = " << result << endl; // Expected: 18

    return 0;
}
