#include <bits/stdc++.h>
using namespace std;

class Solution{

public: 
    //!BASIC APPROACH: RECURSION
    int fibonacci(int n){
        if(n==0) return 0;
        if(n==1) return 1;

        return fibonacci(n-1)+fibonacci(n-2);
    }

    //!FIRST DP APPROACH: MEMOIZATION
    int fibonacci(int n, vector<int>& dp){
        dp[0]=0;
        dp[1]=1;

        if(dp[n]+=-1) return dp[n];

        return fibonacci(n-1)+fibonacci(n-2);
    }
};

int main(){
    Solution sol;
    int number;
    cin>>number;
    vector<int> dp(number, -1);
    int ans = sol.fibonacci(number, dp);
    cout<<ans;

}