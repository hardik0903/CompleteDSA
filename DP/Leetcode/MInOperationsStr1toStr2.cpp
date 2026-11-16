#include <bits/stdc++.h>>
using namespace std;

class Solution {
  public:

    int longestCommonSubsequence(string &s1, string &s2){

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
    int minOperations(string &s1, string &s2) {
        // code here
        int lcsLength = longestCommonSubsequence(s1, s2);
        
        int deletion = s1.size() - lcsLength;
        
        int addition = s2.size() - lcsLength;

        return deletion + addition;
    }
};

int main(){

    string s1, s2;

    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;

    Solution sol;

    int ans = sol.minOperations(s1, s2);
    cout<<ans<<endl;
}