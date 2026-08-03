#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<bool>> dp(arr.size(), vector<bool>(sum+1, 0));
        
        for(int i=0;i<arr.size();i++){
            dp[i][0]=1;
        }
        
        if(sum>=arr[0]){
            dp[0][arr[0]]=1;
        }
        
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<=sum;j++){
                
                bool notTake = dp[i-1][j];
                bool take = false;
                
                if(j>=arr[i]){
                    take = dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = take || notTake;
            }
        }
        
        return dp[arr.size()-1][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }

        if(sum%2!=0){
            return false;
        }

        return isSubsetSum(nums, sum/2);
    }
};

int main(){
    vector<int> arr;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while(ss>>x) arr.push_back(x);

    Solution sol;

    if(sol.canPartition(arr)){
        cout<<"Partition Possible"<<endl;
    }
    else{
        cout<<"Partition Not Possible"<<endl;
    }
}