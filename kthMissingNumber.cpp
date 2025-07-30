#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k;
    }
};

int main() {
    Solution sol;

    // Example Test Case 1
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int result = sol.findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 4};
    k = 2;
    cout << "The " << k << "th missing positive number is: " << sol.findKthPositive(arr2, k) << endl;

    // Test Case 3
    vector<int> arr3 = {2};
    k = 1;
    cout << "The " << k << "th missing positive number is: " << sol.findKthPositive(arr3, k) << endl;

    return 0;
}
