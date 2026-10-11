#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int f(int ind, int sum, vector<vector<int>>& dp, vector<int>& arr){

        if(ind==0){
            if(sum==0 && arr[ind]==0){
                return 2;
            }
            if(sum==0 || sum==arr[ind]){
                return 1;
            }
            return 0;
        }

        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }

        int notPick = f(ind-1, sum, dp, arr);
        int pick = 0;
        if(arr[ind]<=sum){
            pick = f(ind-1, sum-arr[ind], dp, arr);
        }

        return dp[ind][sum] = notPick + pick;
    }

    int countPartition(vector<int>& arr, int difference){

        int totSum = 0;
        int n = arr.size();

        for(int num:arr) totSum+=num;

        int rem = totSum - difference;

        if(rem<0 || rem%2!=0) return 0;

        int size = rem/2;

        vector<vector<int>> dp(n, vector<int>(size+1, -1));

        return f(n, size, dp, arr);
    }
};

int main(){

    int diff;
    int n;
    cout<<"Enter size of Array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter elements at position : "<<i<<" :";
        cin>>num;
        arr[i] = num;
    }

    cout<<"Enter Difference: ";
    cin>>diff;

    Solution sol;

    int ans = sol.countPartition(arr, diff);
    cout<<ans;
}