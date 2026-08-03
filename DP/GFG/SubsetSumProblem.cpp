#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool f(int ind, int target, vector<int>& nums){

        if(target==0) return true;
        if(ind==0) return nums[0] == target;

        bool notTake = f(ind-1, target, nums);
        bool take = false;

        if(nums[ind]<=target){
            take = f(ind-1, target - nums[ind], nums);
        }

        return take || notTake;
    }

    bool subsetSumTarget(vector<int>& nums, int target){
        int n=nums.size();
        return f(n-1, target, nums);
    }
};

int main(){

    vector<int> nums;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    while(ss>>x) nums.push_back(x);

    int k;
    cin>>k;

    Solution sol;
    if(sol.subsetSumTarget(nums, k)){
        cout<<"Element exists";
    }
    else{
        cout<<"Element doesn't exists";
    }
}