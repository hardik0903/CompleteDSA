#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 

    int longestCommonSubsequence(string& s, string& s2){

        int n = s.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s[i-1]==s2[j-1]){
                    dp[i][j] = 1 +dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int longestPalindromeSubsequence(string& s){
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return longestCommonSubsequence(s, s2);
    }
    int minOperationForPalindrome(string& s){
        int n = s.size();
        int longestPalindrome = longestPalindromeSubsequence(s);
        return n - longestPalindrome;
    }
};

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    Solution sol;
    int ans = sol.minOperationForPalindrome(s);
    cout<<ans<<endl;
}