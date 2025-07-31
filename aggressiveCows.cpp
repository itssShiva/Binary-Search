#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canWePlace(vector<int>& nums, int mid, int k, int n) {
        int cntCows = 1;
        int last = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] - last >= mid) {
                cntCows++;
                last = nums[i];
            }
        }
        return cntCows >= k;
    }

    int aggressiveCows(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int n = nums.size();
        int high = nums[n - 1] - nums[0];
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canWePlace(nums, mid, k, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    int result = obj.aggressiveCows(stalls, cows);
    cout << "Maximum minimum distance: " << result << endl;

    return 0;
}
