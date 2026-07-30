#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[i][j];

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int ld = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int rd = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = min(up, min(ld, rd));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minAns=INT_MAX;
        int n = matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int j=0;j<matrix[0].size();j++){
            int ans = f(matrix.size()-1, j, matrix, dp);
            minAns= min(minAns, ans);
        }

        return minAns;
    }
};

int main(){
    int n, m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    Solution sol;
    int ans = sol.minFallingPathSum(arr);
    cout<<ans<<endl;
}

