#include <iostream>
#include <vector>
using namespace std;

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

int count(vector<int>& nums, int n, int x) {
    vector<int> ans = searchRange(nums, x);
    if (ans[0] == -1) return 0;
    return ans[1] - ans[0] + 1;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int x;

    cout << "Enter the number to count its occurrences: ";
    cin >> x;

    int result = count(nums, nums.size(), x);
    cout << "Number of occurrences of " << x << " is: " << result << endl;

    return 0;
}
