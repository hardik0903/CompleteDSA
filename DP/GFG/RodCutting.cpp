#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    // Memoization
    // int f(int ind, int target, vector<int>& price, vector<vector<int>>& dp){
        
    //     if(ind==0){
    //         return ((target/(ind+1))*price[0]);
    //     }
        
    //     if(dp[ind][target]!=-1) return dp[ind][target];
        
    //     int notPick = 0 + f(ind-1, target, price, dp);
    //     int pick = 0;
    //     if(target>=ind+1){
    //         pick = price[ind] + f(ind, target-(ind+1), price, dp);
    //     }
    //     return dp[ind][target] = max(notPick, pick);
    // }
    // int cutRod(vector<int> &price) {
    //     // code here
    //     int n = price.size();
    //     vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
    //     return f(n-1, n, price, dp);
    // }
    
    // Tabulation
    // int cutRod(vector<int> &price) {
    //     // code here
    //     int n = price.size();
    //     vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
    //     for(int i=0;i<=n;i++){
    //         dp[0][i] = ((i)*price[0]);
    //     }
        
    //     for(int ind=1;ind<n;ind++){
    //         for(int tar=0;tar<=n;tar++){
                
    //             int notPick = dp[ind-1][tar];
    //             int pick = 0;
    //             if(tar>=ind+1){
    //                 pick = price[ind] + dp[ind][tar-(ind+1)];
    //             }
                
    //             dp[ind][tar] = max(pick, notPick);
    //         }
    //     }
        
    //     return dp[n-1][n];
    // }
    
    //Space optimization 1
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> prev(n+1, 0);
        
        for(int i=0;i<=n;i++){
            prev[i] = ((i)*price[0]);
        }
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=n;tar++){
                
                int notPick = prev[tar];
                int pick = 0;
                if(tar>=ind+1){
                    pick = price[ind] + prev[tar-(ind+1)];
                }
                
                prev[tar] = max(pick, notPick);
            }
        }
        
        return prev[n];
    }
};

int main(){
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter value at index: "<<i+1<<": ";
        cin>>num;
        arr[i] = num;
    }

    Solution sol;
    int ans = sol.cutRod(arr);
    cout<<endl;
}