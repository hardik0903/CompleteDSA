#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    //!RECURSION APPROACH
    // int f(int ind1, int ind2){

    //     if(ind1==0 && ind2==0) return 1;
    //     if(ind1<0 || ind2<0) return 0;

    //     int up = f(ind1-1, ind2);
    //     int left = f(ind1, ind2-1);

    //     return up+left;
    // }

    // int uniquePaths(int m, int n){
    //     return f(m-1, n-1);
    // }

    //!MEMOIZATION
    int f(int ind1, int ind2, vector<vector<int>>& dp){

        if(ind1==0 && ind2==0) return 1;
        if(ind1<0 || ind2<0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int up = f(ind1-1, ind2, dp);
        int left = f(ind1, ind2-1, dp);

        return dp[ind1][ind2]=up+left;
    }

    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1, n-1, dp);
    }
};

int main(){
    int m,n;
    cin>>m>>n;

    Solution sol;
    int ans = sol.uniquePaths(m, n);
    cout<<ans<<endl;
}