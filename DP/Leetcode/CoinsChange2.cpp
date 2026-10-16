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
    int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){

        if(ind==0){

            return (target%coins[0]==0);
        }

        if(dp[ind][target]!=-1) return dp[ind][target];

        int notPick = f(ind-1, target, coins, dp);
        int pick = 0;
        if(target>=coins[ind]){
            pick = f(ind, target-coins[ind], coins, dp);
        }
        return dp[ind][target] = pick+notPick;
    }

    int coinsChange(int amount, vector<int>& coins){

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins, dp);
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