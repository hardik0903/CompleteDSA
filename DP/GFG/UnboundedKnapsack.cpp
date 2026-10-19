#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Memoization
    // int f(int ind, int cap, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
        
    //     if(ind==0){
            
    //         // if(cap%wt[0]==0){
    //         //     int cal = cap/wt[0];
    //         //     return cal*val[0];
    //         // }
    //         // else{
    //         //     return 0;
    //         // }
            
    //         return ((cap/wt[0])*val[0]);
    //     }
        
    //     if(dp[ind][cap]!=-1) return dp[ind][cap];
        
    //     int notPick = f(ind-1, cap, wt, val, dp);
    //     int pick = 0;
    //     if(cap>=wt[ind]){
    //         pick = val[ind] + f(ind, cap-wt[ind], wt, val, dp);
    //     }
        
    //     return dp[ind][cap] = max(pick, notPick);
    // }
    // int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //     // code here
    //     int n = wt.size();
    //     vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    //     return f(n-1, capacity, wt, val, dp);
    // }
    
    // Tabulation
    //  int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //     // code here
    //     int n = wt.size();
    //     vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
        
    //     for(int i=0;i<=capacity;i++){
    //         dp[0][i] = ((i/wt[0])*val[0]);
    //     }
        
    //     for(int ind=1;ind<n;ind++){
    //         for(int tar=0;tar<=capacity;tar++){
                
    //             int notPick = 0 + dp[ind-1][tar];
    //             int pick = 0;
    //             if(tar>=wt[ind]){
    //                 pick = val[ind] + dp[ind][tar-wt[ind]];
    //             }
    //             dp[ind][tar] = max(pick, notPick);
    //         }
    //     }
    //     return dp[n-1][capacity];
    // }

    // Space Optimization 1 
    // int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    //     // code here
    //     int n = wt.size();
    //     vector<int> prev(capacity+1, 0), cur(capacity+1, 0);
        
    //     for(int i=0;i<=capacity;i++){
    //         prev[i] = ((i/wt[0])*val[0]);
    //     }
        
    //     for(int ind=1;ind<n;ind++){
    //         for(int tar=0;tar<=capacity;tar++){
                
    //             int notPick = 0 + prev[tar];
    //             int pick = 0;
    //             if(tar>=wt[ind]){
    //                 pick = val[ind] + cur[tar-wt[ind]];
    //             }
    //             cur[tar] = max(pick, notPick);
    //         }
    //         prev = cur;
    //     }
    //     return prev[capacity];
    // }
    
    // Space Optimization 2
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<int> prev(capacity+1, 0);
        
        for(int i=0;i<=capacity;i++){
            prev[i] = ((i/wt[0])*val[0]);
        }
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=capacity;tar++){
                
                int notPick = 0 + prev[tar];
                int pick = 0;
                if(tar>=wt[ind]){
                    pick = val[ind] + prev[tar-wt[ind]];
                }
                prev[tar] = max(pick, notPick);
            }
        }
        return prev[capacity];
    }
};

int main(){
    int n;
    cout<<"Enter Number of elements: ";
    cin>>n;

    vector<int> wt(n), val(n);
    for(int i=0;i<n;i++){
        int num1, num2;
        cout<<"Enter weight at index: "<<i<<": ";
        cin>>num1;
        cout<<"Enter value ate index: "<<i<<": ";
        cin>>num2;

        wt[i] = num1;
        val[i] = num2;
    }

    int capacity;
    cout<<"Enter Capacity: ";
    cin>>capacity;

    Solution sol;
    int ans = sol.knapSack(val, wt, capacity);
    cout<<ans<<endl;
}


