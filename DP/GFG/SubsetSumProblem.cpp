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

    bool subsetSumTarget(vector<int>& nums, int target, vector<vector<int>>& dp){
        int n=nums.size();
        
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
    int n=nums.size();
    int k;
    cin>>k;
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    Solution sol;
    if(sol.subsetSumTarget(nums, k, dp)){
        cout<<"Element exists"<<endl;
    }
    else{
        cout<<"Element doesn't exists"<<endl;
    }

    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
    }
}