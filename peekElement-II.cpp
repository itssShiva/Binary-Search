#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n, int m, int mid) {
        int maxValue = -1;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][mid] > maxValue) {
                maxValue = mat[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int maxRowIndex = findMaxIndex(mat, n, m, mid);
            int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;

            if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
                return {maxRowIndex, mid};
            } else if (left > mat[maxRowIndex][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main() {
    Solution solution;

    vector<vector<int>> mat = {
        {70, 50, 40, 30, 20},
        {100, 1, 2, 3, 4}
    };

    vector<int> result = solution.findPeakGrid(mat);

    cout << "Peak Element at: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
