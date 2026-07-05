#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    //!BRUTE-FORCE APPROACH
    // vector<int> maxSlidingWindow(vector<int>& nums, int k){
    //     vector<int> ans;

    //     for(int i=0;i<nums.size()-k;i++){
    //         int maxi=nums[i];
    //         for(int j=i;j<=i+k-1;j++){
    //             maxi=max(maxi,nums[j]);
    //         }
    //         ans.push_back(maxi);
    //     }

    //     return ans;
    // }
    
    //!OPTIMAL SOLUTION
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < nums.size(); i++) {
            if(!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 2, 1, 6};
    int k = 3;

    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Max elements in each sliding window of size " << k << ": ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
