#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    //!RECURSION APPROACH
    // int f(int ind1, int ind2, vector<vector<int>>& triangle){
    //     int n=triangle.size();
    //     if(ind1==n-1) return triangle[n-1][ind2];

    //     int down = triangle[ind1][ind2] + f(ind1+1, ind2, triangle);
    //     int diagonal = triangle[ind1][ind2] + f(ind1+1, ind2+1, triangle);

    //     return min(down, diagonal);

    // }
    // int minimumTotal(vector<vector<int>>& triangle) {

    //     int n = triangle.size();
    //     return f(0, 0, triangle);
    // }

    //!MEMOIZATION APPROACH
    int f(int ind1, int ind2, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n=triangle.size();
        if(ind1==n-1) return triangle[n-1][ind2];

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int down = triangle[ind1][ind2] + f(ind1+1, ind2, triangle, dp);
        int diagonal = triangle[ind1][ind2] + f(ind1+1, ind2+1, triangle, dp);

        return dp[ind1][ind2]=min(down, diagonal);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, dp);
    }

    //!TABULATION APPROACH
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));

    //     for(int j=0;j<n;j++){
    //         dp[n-1][j] = triangle[n-1][j];
    //     }

    //     for(int i=n-2;i>=0;i--){
    //         for(int j=i;j>=0;j--){
    //             int down = triangle[i][j] + dp[i+1][j];
    //             int diagonal = triangle[i][j] + dp[i+1][j+1];

    //             dp[i][j] = min(down, diagonal);
    //         }
    //     }

    //     return dp[0][0];
    // }
};

int main(){
    vector<vector<int>> arr;
    int n;
    cin>>n;

    cin.ignore(); 
    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> row;
        int val;

        while (ss >> val) {
            row.push_back(val);
        }

        arr.push_back(row);
    }

    Solution sol;
    int ans = sol.minimumTotal(arr);
    cout<<ans<<endl;
}