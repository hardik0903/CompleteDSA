#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //!Brute-force approach
    // int longestOnes(vector<int>& nums, int k){
    //     int maxlen=0;
    //     for(int i=0;i<nums.size();i++){
    //         int zeroes=0;
    //         for(int j=i;j<nums.size();j++){
    //             if(nums[j]==0) zeroes++;
    //             if(zeroes<=k) maxlen=max(maxlen,j-i+1);
    //             else break;
    //         }
    //     }
    //     return maxlen;
    // }

    //!Better Approach
    // int longestOnes(vector<int>& nums, int k) {
    //     int l=0,r=0,maxlen=0,zeroes=0;
    //     int n=nums.size();

    //     while(r<n){
    //         if(nums[r]==0) zeroes++;
    //         if(zeroes>k){
    //             if(nums[l]==0) zeroes--;
    //             l++;
    //         }
    //         if(zeroes<=k) maxlen=max(maxlen,r-l+1);
    //         r++;
    //     }
    //     return maxlen;
    // }

    //!Most Optimal Answer
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxlen=0,zeroes=0;
        int n=nums.size();

        while(r<n){
            if(nums[r]==0) zeroes++;
            while(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(zeroes<=k) maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};

int main(){
    Solution sol;
    vector<int> arr={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    int ans=sol.longestOnes(arr,k);
    cout<<"Calculated Max Subarray length is: "<<ans<<" Whereas answer is: 6"<<endl;
return 0;
}