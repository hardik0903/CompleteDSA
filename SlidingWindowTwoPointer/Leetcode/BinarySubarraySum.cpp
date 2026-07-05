#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int goal){

        if(goal<0) return 0;
        int l=0,r=0,sum=0,cnt=0;
        int n=nums.size();

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums,goal-1);
    }
};

int main(){

    vector<int> arr={1,0,1,0,1};
    int goal=2;
    Solution sol;
    int ans=sol.numSubarraysWithSum(arr,goal);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is:4"<<endl;
return 0;
}