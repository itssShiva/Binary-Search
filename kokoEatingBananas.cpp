#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxElement(vector<int>& piles) {
        int maxElement = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxElement = max(maxElement, piles[i]);
        }
        return maxElement;
    }

    long long calculateTime(vector<int>& piles, int mid) {
        long long totalhrs = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            // Avoid using (double), use pure integer math
            totalhrs += (piles[i] + mid - 1) / mid;  // Integer ceiling
        }
        return totalhrs;
    }

    int minimumRateToEatBananas(vector<int>& nums, int h) {
        int low = 1;
        int high = maxElement(nums);
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalhrs = calculateTime(nums, mid);
            if (totalhrs <= h) {
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
    int n;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter pile sizes:\n";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int h;
    cout << "Enter total hours available (h): ";
    cin >> h;

    Solution sol;
    int result = sol.minimumRateToEatBananas(piles, h);

    cout << "Minimum rate to eat all bananas in " << h << " hours is: " << result << endl;

    return 0;
}
