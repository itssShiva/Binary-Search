#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high = x;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = mid * mid;
            if (val <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};

int main() {
    Solution sol;
    int x;

    cout << "Enter a number to find its integer square root: ";
    cin >> x;

    int result = sol.mySqrt(x);
    cout << "The integer square root of " << x << " is: " << result << endl;

    return 0;
}
