#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void subsetSum(vector<int>& arr, int sum, vector<vector<bool>>& dp){
        
        for(int i=0;i<arr.size();i++){
            dp[i][0]=1;
        }
        
        if(sum>=arr[0]){
            dp[0][arr[0]] = 1;
        }
        
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<=sum;j++){
                
                bool notTake = dp[i-1][j];
                bool take = false;
                
                if(j>=arr[i]){
                    take = dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = take || notTake;
            }
        }
    }
    int minDifference(vector<int>& arr) {
        // code here
        
        int sum = 0;
        
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
        }
        
        vector<vector<bool>> dp(arr.size(), vector<bool>(sum+1, 0));
        
        subsetSum(arr, sum, dp);
        
        int mini = 1e9;
        for(int i=0;i<=sum;i++){
            
            if(dp[arr.size()-1][i] == 1){
                
                int s1=i;
                int s2 = sum-i;
                mini = min(mini, abs(s2-s1));
            }
        }
        return mini;
    }
};

int main(){
    vector<int> arr;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while(ss>>x) arr.push_back(x);

    Solution sol;
    int ans = sol.minDifference(arr);
    cout<<ans<<endl;
}
