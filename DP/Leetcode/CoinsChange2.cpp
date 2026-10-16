#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    // Recursion
    // int f(int ind, int target, vector<int>& coins){

    //     if(ind==0){

    //         return (target%coins[0]==0);
    //     }

    //     int notPick = f(ind-1, target, coins);
    //     int pick = 0;
    //     if(target>=coins[ind]){
    //         pick = f(ind, target-coins[ind], coins);
    //     }
    //     return pick+notPick;
    // }

    // int coinsChange(int amount, vector<int>& coins){

    //     int n = coins.size();
    //     return f(n-1, amount, coins);
    // }

    // Memoization
    // int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){

    //     if(ind==0){

    //         return (target%coins[0]==0);
    //     }

    //     if(dp[ind][target]!=-1) return dp[ind][target];

    //     int notPick = f(ind-1, target, coins, dp);
    //     int pick = 0;
    //     if(target>=coins[ind]){
    //         pick = f(ind, target-coins[ind], coins, dp);
    //     }
    //     return dp[ind][target] = pick+notPick;
    // }

    // int coinsChange(int amount, vector<int>& coins){

    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //     int ans =  f(n-1, amount, coins, dp);

    //     for(int i=0;i<n;i++){
    //         for(int tar=0;tar<=amount;tar++){
    //             cout<<dp[i][tar]<<" ";
    //         }
    //         cout<<endl;
    //     }

    //     return ans;
    // }

    //Tabulation
    // int coinsChange(int amount, vector<int>& coins){

    //     int n = coins.size();
    //     vector<vector<long long>> dp(n, vector<long long>(amount+1, 0));

    //     for(int i=0;i<=amount;i++){
    //         dp[0][i] = (i%coins[0]==0);
    //     }

    //     for(int ind=1;ind<n;ind++){
    //         for(int tar=0;tar<=amount;tar++){

    //             int notPick=dp[ind-1][tar];
    //             int pick = 0;
    //             if(tar>=coins[ind]){
    //                 pick = dp[ind][tar-coins[ind]];
    //             }

    //             dp[ind][tar] = (long long)pick+notPick;
    //         }
    //     }

    //     return dp[n-1][amount];
    // }

    //Space optimization 1
    int coinsChange(int amount, vector<int>& coins){

        int n = coins.size();
        vector<long long> prev(amount+1, 0), cur(amount+1, 0);

        for(int i=0;i<=amount;i++){
            prev[i] = (i%coins[0]==0);
        }

        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){

                int notPick = prev[tar];
                int pick = 0;
                if(tar>=coins[ind]){
                    pick = cur[tar-coins[ind]];
                }

                cur[tar] = (long long)pick+notPick;
            }
            prev = cur;
        }

        return prev[amount];
    }
};

int main(){

    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter value at index: "<<i<<": ";
        cin>>num;
        arr[i] = num;
    }
    int target;
    cout<<"Enter target value: ";
    cin>>target;

    Solution sol;
    int ans = sol.coinsChange(target, arr);
    cout<<ans<<endl;
}