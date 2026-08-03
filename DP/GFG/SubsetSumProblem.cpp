#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    //! RECURSION APPROACH
    // bool f(int ind, int target, vector<int>& nums){

    //     if(target==0) return true;
    //     if(ind==0) return nums[0] == target;

    //     bool notTake = f(ind-1, target, nums);
    //     bool take = false;

    //     if(nums[ind]<=target){
    //         take = f(ind-1, target - nums[ind], nums);
    //     }

    //     return take || notTake;
    // }

    // bool subsetSumTarget(vector<int>& nums, int target){
    //     int n=nums.size();
    //     return f(n-1, target, nums);
    // }

    //!MEMOIZATION APPROACH
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){

        if(target==0) return true;
        if(ind==0) return nums[0] == target;

        if(dp[ind][target]!=-1) return dp[ind][target];

        bool notTake = f(ind-1, target, nums, dp);
        bool take = false;

        if(nums[ind]<=target){
            take = f(ind-1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = take || notTake;
    }

    bool subsetSumTarget(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (target, -1));
        return f(n-1, target, nums, dp);
    }
};

int main(){

    vector<int> nums;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while(ss>>x) nums.push_back(x);

    int k;
    cin>>k;

    Solution sol;
    if(sol.subsetSumTarget(nums, k)){
        cout<<"Element exists"<<endl;
    }
    else{
        cout<<"Element doesn't exists"<<endl;
    }
}