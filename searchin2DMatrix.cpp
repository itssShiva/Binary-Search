#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        if(n == 0) return false;
        int m = mat[0].size();
        int low = 0;
        int high = n * m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;  // safer midpoint calculation
            int row = mid / m;
            int col = mid % m;
            if(mat[row][col] == target) return true;
            else if(mat[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example matrix (sorted in row-wise and column-wise manner)
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int target = 3;
    bool found = sol.searchMatrix(mat, target);

    if(found) {
        cout << "Target " << target << " found in matrix." << endl;
    } else {
        cout << "Target " << target << " NOT found in matrix." << endl;
    }

    return 0;
}
