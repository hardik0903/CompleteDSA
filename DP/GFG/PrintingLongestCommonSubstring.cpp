#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string printLongestCommonSubstring(string& s1, string& s2){

        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){

                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }

        int maxVal = 0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                maxVal = max(maxVal, dp[i][j]);
            }
        }
        
        int index = 0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(dp[i][j]==maxVal){
                    index = j;
                }
            }
        }

        string s = s2.substr(index, maxVal);
        return s;
    }
};

int main(){

    string s1, s2;
    
    cout<<"Enter first string: ";
    cin>>s1;

    cout<<"Enter second string: ";
    cin>>s2;

    Solution sol;
    string ans = sol.printLongestCommonSubstring(s1, s2);
    cout<<ans<<endl;
}