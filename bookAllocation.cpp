#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   

using namespace std;
class Solution {
public:
    int countStudents(vector<int>& nums, int mid, int n) {
        int stu = 1;
        int pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + nums[i] <= mid) {
                pagesStudent += nums[i];
            } else {
                stu++;
                pagesStudent = nums[i];
            }
        }
        return stu;
    }
    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        if (m > n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int noOfStu = countStudents(nums, mid, n);
            if (noOfStu > m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

int main() {
    // Example test case: books = [12, 34, 67, 90], students = 2
    vector<int> books = {12, 34, 67, 90};
    int m = 2;

    Solution sol;
    int result = sol.findPages(books, m);

    cout << "Minimum number of pages = " << result << endl; // Should output: 113

    return 0;
}
