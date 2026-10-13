#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    //Recursion 
    // int f(int ind, int target, vector<int>& coins){

    //     if(ind==0){

    //         if(target%coins[0] == 0){
    //             return target/coins[0];
    //         }
    //         else{
    //             return 1e9;
    //         }
    //     }

    //     int notPick = 0 + f(ind-1, target, coins);
    //     int pick = INT_MAX;
    //     if(coins[ind] <= target){
    //         pick = 1 + f(ind, target-coins[ind], coins);
    //     }

    //     return min(notPick, pick);
    // }

    // int coinsChange(int amount, vector<int>& coins){
    //     int n = coins.size();
    //     return f(n-1, amount, coins);
    // }

    //Memoization
    // int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){

    //     if(ind==0){

    //         if(target%coins[0] == 0){
    //             return target/coins[0];
    //         }
    //         else{
    //             return 1e9;
    //         }
    //     }  

    //     if(dp[ind][target]!=-1){
    //         return dp[ind][target];
    //     }

    //     int notPick = 0 + f(ind-1, target, coins, dp);
    //     int pick = INT_MAX;
    //     if(coins[ind] <= target){
    //         pick = 1 + f(ind, target-coins[ind], coins, dp);
    //     }

    //     return dp[ind][target] = min(notPick, pick);
    // }

    // int coinsChange(int amount, vector<int>& coins){
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //     int ans = f(n-1, amount, coins, dp);

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<=amount;j++){
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return ans;
    // }

    //Tabulation
    // int coinsChange(int amount, vector<int>& coins){
        
    //     int n = coins.size();
    //     vector<vector<int>> dp(n, vector<int>(amount+1, 0));

    //     for(int i=coins[0];i<=amount;i+=coins[0]){
    //         dp[0][i] = i/coins[0];
    //     }

    //     for(int i=1;i<=amount; i++){
    //         if(dp[0][i]==0) dp[0][i]=1e9;
    //     }

    //     for(int ind=1;ind<n;ind++){
    //         for(int tar = 0;tar<=amount;tar++){
                
    //             int notPick = 0 + dp[ind-1][tar];
    //             int pick = INT_MAX;
    //             if(coins[ind]<=tar){
    //                 pick = 1 + dp[ind][tar-coins[ind]];
    //             }
    //             dp[ind][tar] = min(pick, notPick);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<=amount;j++){
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return dp[n-1][amount];
    // }

    //Space optimization 1
    // int coinsChange(int amount, vector<int>& coins){
        
    //     int n = coins.size();
    //     vector<int> prev(amount+1, 0), cur(amount+1, 0);

    //     for(int i=coins[0];i<=amount;i+=coins[0]){
    //         prev[i] = i/coins[0];
    //     }

    //     for(int i=1;i<=amount; i++){
    //         if(prev[i]==0) prev[i]=1e9;
    //     }

    //     for(int ind=1;ind<n;ind++){
    //         for(int tar = 0;tar<=amount;tar++){
                
    //             int notPick = 0 + prev[tar];
    //             int pick = INT_MAX;
    //             if(coins[ind]<=tar){
    //                 pick = 1 + cur[tar-coins[ind]];
    //             }
    //             cur[tar] = min(pick, notPick);
    //         }
    //         prev = cur;
    //     }
    //     // for(int i=0;i<n;i++){
    //     //     for(int j=0;j<=amount;j++){
    //     //         cout<<dp[i][j]<<" ";
    //     //     }
    //     //     cout<<endl;
    //     // }
    //     return prev[amount];
    // }
    
    //Space optimization 2
    int coinsChange(int amount, vector<int>& coins){
        
        int n = coins.size();
        vector<int> prev(amount+1, 0);

        for(int i=coins[0];i<=amount;i+=coins[0]){
            prev[i] = i/coins[0];
        }

        for(int i=1;i<=amount; i++){
            if(prev[i]==0) prev[i]=1e9;
        }

        for(int ind=1;ind<n;ind++){
            for(int tar = 0;tar<=amount;tar++){
                
                int notPick = 0 + prev[tar];
                int pick = INT_MAX;
                if(coins[ind]<=tar){
                    pick = 1 + prev[tar-coins[ind]];
                }
                prev[tar] = min(pick, notPick);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=amount;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return prev[amount];
    }
};

int main(){
    int n;
    cout<<"Enter Number of elements: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter values: ";
        cin>>num;
        arr[i] = num;
    }

    Solution sol;

    int target;
    cout<<"Enter target: ";
    cin>>target;

    int ans = sol.coinsChange(target, arr);
    cout<<ans<<endl;


}