#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Recursion
    // int f(int ind, int sum, vector<int>& arr){
        
    //     if(ind ==0){

    //         if(arr[0]==0 && sum==0){
    //             return 2;
    //         }
    //         else if(arr[ind]==sum || sum==0){
    //             return 1;
    //         }
    //         else return 0;
    //     }

    //     int notPick = f(ind-1, sum, arr);
    //     int pick = 0;
    //     if(sum>=arr[ind]){
    //         pick = f(ind-1, sum-arr[ind], arr);
    //     }

    //     return pick+notPick;
    // }

    // int countPartition(int target, vector<int>& arr){
    //     int n = arr.size();

    //     int totSum = 0;
    //     for(int num:arr){
    //         totSum += num;
    //     }
    //     int rem = totSum - target;

    //     if(rem<0 || rem%2!=0) return 0;

    //     int size = rem/2;

    //     return f(n-1, size, arr);
    // }

    // int targetSum(vector<int>& nums, int target){
    //     int n = nums.size();

    //     return countPartition(target, nums);
    // }

    //Memoization
    // int f(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp){
        
    //     if(ind ==0){

    //         if(arr[0]==0 && sum==0){
    //             return 2;
    //         }
    //         else if(arr[ind]==sum || sum==0){
    //             return 1;
    //         }
    //         else return 0;
    //     }

    //     if(dp[ind][sum]!=-1) return dp[ind][sum];

    //     int notPick = f(ind-1, sum, arr, dp);
    //     int pick = 0;
    //     if(sum>=arr[ind]){
    //         pick = f(ind-1, sum-arr[ind], arr, dp);
    //     }

    //     return dp[ind][sum] = pick+notPick;
    // }

    // int countPartition(int target, vector<int>& arr){
    //     int n = arr.size();

    //     int totSum = 0;
    //     for(int num:arr){
    //         totSum += num;
    //     }
    //     int rem = totSum - target;

    //     if(rem<0 || rem%2!=0) return 0;

    //     int size = rem/2;
    //     vector<vector<int>> dp(n, vector<int>(size+1, -1));

    //     int ans = f(n-1, size, arr, dp);

    //     for(int i = 0;i<n;i++){
    //         for(int j = 0;j<=size;j++){
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return ans;
    // }

    // int targetSum(vector<int>& nums, int target){
    //     int n = nums.size();

    //     return countPartition(target, nums);
    // }

    //Tabulation
    int targetSum(vector<int>& nums, int target){
        int n = nums.size();

        int totSum = 0;

        for(int num:nums){
            totSum +=num;
        }

        int rem = totSum - target;
        if(rem<0 || rem%2!=0) return 0;

        int size = rem/2;
        
        vector<vector<int>> dp(n, vector<int>(size+1, 0));

        for(int i=0;i<=size;i++){
            if(i==0 && nums[0]==0){
                dp[0][i] = 2;
            }
            else if(i==0 || nums[0]==i){
                dp[0][i] = 1;
            }
            else dp[0][i] = 0;
        }

        for(int ind = 1;ind<n;ind++){
            for(int tar = 0;tar<=size;tar++){

                int notPick = dp[ind-1][tar];
                int pick = 0;
                if(tar>=nums[ind]){
                    pick = dp[ind-1][tar-nums[ind]];
                }

                dp[ind][tar] = pick+notPick;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<=size;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return dp[n-1][size];
    }
};

int main(){

    int target;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter elements at position "<<i<<" :";
        cin>>num;
        arr[i] = num;
    }

    cout<<"Enter target value: ";
    cin>>target;

    Solution sol;
    int ans = sol.targetSum(arr, target);
    cout<<ans<<endl;
}