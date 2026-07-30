#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //!RECURSION
    int f(int i, int j, vector<vector<int>>& matrix){
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[i][j];

        int up = matrix[i][j] + f(i-1, j, matrix);
        int ld = matrix[i][j] + f(i-1, j-1, matrix);
        int rd = matrix[i][j] + f(i-1, j+1, matrix);

        return min(up, min(ld, rd));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minAns=INT_MAX;
        int n = matrix.size();
        int m=matrix[0].size();
\
        for(int j=0;j<matrix[0].size();j++){
            int ans = f(matrix.size()-1, j, matrix);
            minAns= min(minAns, ans);
        }

        return minAns;
    }

    //!MEMOIZATION
    // int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     if(j<0 || j>=matrix[0].size()) return 1e9;
    //     if(i==0) return matrix[i][j];

    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }

    //     int up = matrix[i][j] + f(i-1, j, matrix, dp);
    //     int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
    //     int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);

    //     return dp[i][j] = min(up, min(ld, rd));

    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int minAns=INT_MAX;
    //     int n = matrix.size();
    //     int m=matrix[0].size();
    //     vector<vector<int>> dp(n, vector<int>(m, -1));

    //     for(int j=0;j<matrix[0].size();j++){
    //         int ans = f(matrix.size()-1, j, matrix, dp);
    //         minAns= min(minAns, ans);
    //     }

    //     return minAns;
    // }

    //! TABULATION
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();

    //     vector<vector<int>> dp(n, vector<int>(m, 0));

    //     for(int j=0;j<m;j++){
    //         dp[0][j] = matrix[0][j];
    //     }

    //     for(int i=1;i<n;i++){
    //         for(int j=0;j<m;j++){

    //             int up = matrix[i][j] + dp[i-1][j];
    //             int ld = 1e9, rd=1e9;
    //             if(j-1>=0){
    //                 ld = matrix[i][j] + dp[i-1][j-1];
    //             }

    //             if(j+1<m){
    //                 rd = matrix[i][j] + dp[i-1][j+1];
    //             }

    //             dp[i][j] = min(up, min(ld, rd));
    //         }
    //     }

    //     int minAns=dp[n-1][0];

    //     for(int j=1;j<m;j++){
    //         minAns = min(minAns, dp[n-1][j]);
    //     }

    //     return minAns;
    // }
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    Solution sol;
    int ans = sol.minFallingPathSum(matrix);
    cout<<ans<<endl;
}