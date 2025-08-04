#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& nums, int mid, int m) {
        int high = m - 1;
        int low = 0;
        int ans = m;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (nums[middle] > mid) {
                ans = middle;
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        return ans;
    }

    int countSmallEqual(vector<vector<int>>& matrix, int n, int m, int mid) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(matrix[i], mid, m);
        }
        return cnt;
    }

    int findMedian(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (n * m) / 2;

        while (low <= high) {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(matrix, n, m, mid);
            if (smallEqual <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int median = sol.findMedian(matrix);
    cout << "Median is: " << median << endl;

    return 0;
}
