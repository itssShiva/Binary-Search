#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    int minimum(vector<int>& bloomDay) {
        int small = INT_MAX;
        for (int val : bloomDay) {
            small = min(small, val);
        }
        return small;
    }

    int maximum(vector<int>& bloomDay) {
        int greatest = INT_MIN;
        for (int val : bloomDay) {
            greatest = max(greatest, val);
        }
        return greatest;
    }

    bool possible(vector<int>& bloomDay, int mid, int m, int k) {
        int count = 0, noOfB = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                noOfB += count / k;
                count = 0;
            }
            if (noOfB >= m) return true;
        }
        noOfB += count / k;
        return noOfB >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * m * k > n) return -1;

        int low = minimum(bloomDay);
        int high = maximum(bloomDay);
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k)) {
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
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    Solution sol;
    int result = sol.minDays(bloomDay, m, k);

    cout << "Minimum number of days: " << result << endl;

    return 0;
}
