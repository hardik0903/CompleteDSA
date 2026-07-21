#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int f(int n, vector<int>& nums){
        if(n==0) return nums[0];
        if(n<0) return 0;

        int pick = nums[n] + f(n-2, nums);
        int notpick = 0 + f(n-1, nums);

        return max(pick, notpick);

    }

    int rob(vector<int>& nums){
        int n =nums.size();

        return f(n-1, nums);
    }
};

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Solution sol;
    int ans = sol.rob(arr);
    cout<<ans;
}