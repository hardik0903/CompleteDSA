#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, 0));
        
        dp[0][0] = 1;
        
        if(arr[0] <= target){
            dp[0][arr[0]] += 1;  
        }
        
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<=target;j++){
                
                int notTake = dp[i-1][j];
                int take = 0;
                
                if(j>=arr[i]){
                    take = dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = take + notTake;
            }
        }
        return dp[arr.size()-1][target];
    }
};

int main(){
    vector<int> arr;
    string line;
    getline(cin, line);
    int x;
    stringstream ss(line);
    while(ss>>x) arr.push_back(x);

    int target;
    cin>>target;

    Solution sol;
    int ans = sol.perfectSum(arr, target);
    cout<<ans<<endl;
}