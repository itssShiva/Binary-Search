#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
    int sumByD(vector<int>& nums, int mid) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(mid));
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int limit) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= limit) {
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

    vector<int> nums = {1, 2, 5, 9};
    int limit = 6;

    int result = sol.smallestDivisor(nums, limit);
    cout << "Smallest divisor = " << result << endl;

    return 0;
}
