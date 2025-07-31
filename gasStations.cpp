#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> howMany(n-1, 0);
        priority_queue<pair<long double, int>> pq;
        for (int i = 0; i < n - 1; i++) {
            pq.push({(long double)(arr[i+1] - arr[i]), i});
        }
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;
            long double inDiff = arr[secInd+1] - arr[secInd];
            long double newSecLen = inDiff / (long double)(howMany[secInd] + 1);
            pq.push({newSecLen, secInd});
        }
        return pq.top().first;
    }
};

int main() {
    // Example: Positions of gas stations
    vector<int> arr = {1, 2, 3, 6, 7, 9};
    int k = 2; // Number of additional gas stations to add

    Solution sol;
    long double result = sol.minimiseMaxDistance(arr, k);

    cout.precision(10);
    cout << "Minimum possible maximum distance: " << result << endl;

    return 0;
}
