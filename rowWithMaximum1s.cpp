#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:   

    int lowerBound(vector<int>arr,int col,int x){
        int low=0;
        int high=col;
        int ans=col;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
                ans=mid;
            high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }

  int rowWithMax1s(vector<vector<int>> &mat) {
    int rows = mat.size();
    if (rows == 0) return -1;
    int cnt_max=0;
    int ind=-1;
    int col = mat[0].size();
    for(int i=0;i<rows;i++){
        int cnt_ones=col-lowerBound(mat[i],col,1);
        if(cnt_ones>cnt_max){
            cnt_max=cnt_ones;
            ind=i;
        }
    }
    return ind;
  }
};

int main() {
  Solution sol;

  // Example matrix
  vector<vector<int>> mat = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 0}
  };

  int result = sol.rowWithMax1s(mat);
  cout << "Row with maximum number of 1s is: " << result << endl;

  return 0;
}
