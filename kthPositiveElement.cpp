#include <bits/stdc++.h>
using namespace std;

int ninjaAndLadoos(vector<int> &a, vector<int> &b, int n1, int n2, int k) {
    if (n1 > n2) return ninjaAndLadoos(b, a, n2, n1, k);

    int low = max(k - n2, 0);
    int high = min(k, n1);
    int left = k;

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = (mid1 > 0) ? a[mid1 - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
        int r1 = (mid1 < n1) ? a[mid1] : INT_MAX;
        int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }
    return 0;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};

    int n1 = a.size();
    int n2 = b.size();

    int k = 5;  // Example: find the 5-th smallest element in combined arrays

    int result = ninjaAndLadoos(a, b, n1, n2, k);

    cout << "The " << k << "-th smallest element in the merged arrays is: " << result << endl;

    return 0;
}
