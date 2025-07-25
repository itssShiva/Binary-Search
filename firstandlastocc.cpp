#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getFirst(vector<int>& nums, int target, int low, int high, int n) {
        int first = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    int getLast(vector<int>& nums, int target, int low, int high, int n) {
        int last = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int firstocc = getFirst(nums, target, low, high, n);
        if (firstocc == -1) return {-1, -1};
        int lastocc = getLast(nums, target, low, high, n);
        return {firstocc, lastocc};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target;

    cout << "Enter target to find its first and last occurrence: ";
    cin >> target;

    vector<int> result = sol.searchRange(nums, target);
    
    cout << "First Occurrence: " << result[0] << endl;
    cout << "Last Occurrence: " << result[1] << endl;

    return 0;
}
