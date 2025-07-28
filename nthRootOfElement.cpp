#include <iostream>
using namespace std;

class Solution {
public:
    int nRoot(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid;
            if (ans > m) return 2;  // mid^n > m
        }
        if (ans == m) return 1;     // mid^n == m
        return 0;                   // mid^n < m
    }

    int NthRoot(int N, int M) {
        int low = 1, high = M;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = nRoot(mid, N, M);
            if (midN == 1) return mid;
            else if (midN == 0) low = mid + 1;
            else high = mid - 1;
        }
        return -1; // No integer Nth root
    }
};

int main() {
    Solution sol;
    int N, M;

    cout << "Enter N (root degree): ";
    cin >> N;
    cout << "Enter M (target number): ";
    cin >> M;

    int result = sol.NthRoot(N, M);

    if (result != -1)
        cout << "The " << N << "th root of " << M << " is: " << result << endl;
    else
        cout << "No integer " << N << "th root exists for " << M << endl;

    return 0;
}
