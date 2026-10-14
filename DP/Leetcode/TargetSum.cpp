#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Recursion
    int f(int ind, int sum, vector<int>& arr){
        
        if(ind ==0){

            if(arr[0]==0 && sum==0){
                return 2;
            }
            else if(arr[ind]==sum || sum==0){
                return 1;
            }
            else return 0;
        }

        int notPick = f(ind-1, sum, arr);
        int pick = 0;
        if(sum>=arr[ind]){
            pick = f(ind-1, sum-arr[ind], arr);
        }

        return pick+notPick;
    }

    int countPartition(int target, vector<int>& arr){
        int n = arr.size();

        int totSum = 0;
        for(int num:arr){
            totSum += num;
        }
        int rem = totSum - target;

        if(rem<0 || rem%2!=0) return 0;

        int size = rem/2;

        return f(n-1, size, arr);
    }

    int targetSum(vector<int>& nums, int target){
        int n = nums.size();

        return countPartition(target, nums);
    }
};

int main(){

    int target;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        int num;
        cout<<"Enter elements at position "<<i<<" :";
        cin>>num;
        arr[i] = num;
    }

    cout<<"Enter target value: ";
    cin>>target;

    Solution sol;
    int ans = sol.targetSum(arr, target);
    cout<<ans<<endl;
}