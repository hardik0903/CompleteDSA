#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;


bool IsPossible(vector<int>& arr , int sum, int k){
    int n=arr.size();
    int cnt=1;
    int currentSum=0;

    for(int i=0;i<n;i++){
        if(arr[i]+currentSum<=sum){
            currentSum+=arr[i];
        }
        else{
            cnt++;
            currentSum=arr[i];
        }
    }

    return(cnt<=k);
}
int splitArray(vector<int>& nums, int k) {
    
    int n=nums.size();

    if(k>n) return -1;

    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);

    while(low<=high){
        int mid=(low+high)/2;

        if(IsPossible(nums,mid,k)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return low;
}

int main(){
    vector<int> arr={25,46,28,49,24};
    int ans=splitArray(arr,4);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 71";
return 0;
}