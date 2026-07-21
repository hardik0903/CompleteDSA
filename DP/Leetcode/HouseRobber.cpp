#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    //! RECURSION
    // int f(int n, vector<int>& nums){
    //     if(n==0) return nums[0];
    //     if(n<0) return 0;

    //     int pick = nums[n] + f(n-2, nums);
    //     int notpick = 0 + f(n-1, nums);

    //     return max(pick, notpick);

    // }

    // int rob(vector<int>& nums){
    //     int n =nums.size();

    //     return f(n-1, nums);
    // }

    //!MEMOIZATION
    // int f(int n, vector<int>& dp, vector<int>& nums){

    //     if(n==0) return nums[n];
    //     if(n<0) return 0;

    //     if(dp[n]!=-1) return dp[n];

    //     int pick = nums[n] + f(n-2, dp, nums);
    //     int notpick = 0 + f(n-1, dp, nums);

    //     return dp[n] = max(pick, notpick);
    // }

    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n, -1);
    //     return f(n-1, dp, nums);
    // }

    //!TABULATION
    int f(int n, vector<int>& nums, vector<int>& dp){
        dp[0]=0;

        for(int i=1;i<=n;i++){

            int pick = nums[i] + (i-2<0)?0:nums[i-2];
            int notpick = 0 + nums[i-1];

            dp[i] = max(pick, notpick);
        }

        return dp[n];
    }

    int rob(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        return f(n-1, nums, dp);
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Solution sol;
    int ans = sol.rob(arr);
    cout<<ans;
}