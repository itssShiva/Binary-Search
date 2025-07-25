#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getfloor(vector<int>nums,int x,int low,int high,int n){
       int ans=-1;
        while(low<=high){
        int mid=(low+high)/2;
            if(nums[mid]<=x){
                ans=nums[mid];
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
    }
    return ans;
    }


    int getceil(vector<int>nums,int x,int low,int high,int n){
       int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=x){
                ans=nums[mid];
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
    }
    return ans;
    }



    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int floor=getfloor(nums,x,low,high,n);
        int ceil=getceil(nums,x,low,high,n);
        return {floor,ceil};

        }
    
};


int main() {
    Solution sol;
    vector<int> nums = {10, 20, 30, 40, 50};
    int x;

    cout << "Enter the number to find floor and ceil: ";
    cin >> x;

    vector<int> result = sol.getFloorAndCeil(nums, x);

    cout << "Floor: " << result[0] << endl;
    cout << "Ceil: " << result[1] << endl;

    return 0;
}