#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example matrix: each row and column is sorted
    vector<vector<int>> matrix = {
        {1,  4,  7, 11, 15},
        {2,  5,  8, 12, 19},
        {3,  6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 5;
    bool found = sol.searchMatrix(matrix, target);

    if (found) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " NOT found in the matrix." << endl;
    }

    return 0;
}
