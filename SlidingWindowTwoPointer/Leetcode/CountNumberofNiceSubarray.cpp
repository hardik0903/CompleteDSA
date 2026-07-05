#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int goal){

        if(goal<0) return 0;
        int l=0,r=0,sum=0,cnt=0;
        int n=nums.size();

        while(r<n){
            sum+=nums[r]%2;
            while(sum>goal){
                sum=sum-nums[l]%2;
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberofSubarray(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums,goal-1);
    }
};

int main(){

    vector<int> arr={1,5,2,1,1};
    int goal=3;
    Solution sol;
    int ans=sol.numberofSubarray(arr,goal);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is:2"<<endl;
return 0;
}