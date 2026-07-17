#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    //!RECURSIVE APPROACH
    // int f(int index, vector<int>& heights){
    //     if(index==0) return 0;
    //     int left = f(index-1, heights) + abs(heights[index] - heights[index-1]);
    //     int right=INT_MAX;
    //     if(index>1){
    //         right = f(index-2, heights) + abs(heights[index] - heights[index-2]);
    //     }

    //     return min(left, right);
    // }
    // int frogJump(vector<int>& heights){
    //     int n=heights.size();
    //     return f(n-1, heights);
    // }

    int f(int index, vector<int>& heights, vector<int>& dp){
        if(index==0) return 0;
        if(dp[index]!=-1) return dp[index];

        int left = f(index-1, heights, dp) + abs(heights[index] - heights[index-1]);
        int right=INT_MAX;
        if(index>1){
            right =f(index-2, heights, dp) + abs(heights[index] - heights[index-2]);
        }

        return dp[index] = min(left, right);
    }

    int frogJump(vector<int>& heights){
        int n=heights.size();
        vector<int> dp(n, -1);

        return f(n-1, heights, dp);
    }
};

int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int x;
    while(ss>>x) arr.push_back(x);
    Solution sol;
    int ans = sol.frogJump(arr);
    cout<<ans;
}