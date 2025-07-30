#include <iostream>
#include <vector>
#include <numeric>     // for accumulate
#include <algorithm>   // for max_element
using namespace std;

class Solution {
public:
    int daysReq(vector<int>& weights, int mid) {
        int load = 0;
        int day = 1;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            if (load + weights[i] > mid) {
                day += 1;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = (low + high) / 2;
            int numOfDays = daysReq(weights, mid);
            if (numOfDays <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum ship capacity to deliver in " << days << " days = " << result << endl;

    return 0;
}
