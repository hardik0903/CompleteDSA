#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int LargestSubArray(vector<int>& arr,int k){
    int n=arr.size();
    int left=0;
    int right=0;
    int maxi=0;
    int sum=arr[0];

    while(right<n){
        while(sum>k && left<=right){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxi=max(maxi,(right-left+1));
        }
        right++;
        if(left<n){
            sum+=arr[right];
        }
    }
    return maxi;
}

int main(){

    vector<int> arr={1,2,3,1,1,1,1,3,3};

    int answer=LargestSubArray(arr,6);

    cout<<"Calculated Answer is "<<answer<<" Whereas Real Answer is: 4";
return 0;
}