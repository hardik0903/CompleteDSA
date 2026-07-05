#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!LINEAR SEARCH
// int maxEl(vector<int>& arr){
//     int n=arr.size();
//     int maxi=0;
//     for(int i=0;i<n;i++){
//         maxi=max(maxi,arr[i]);
//     }
//     return maxi;
// }

// bool possible(vector<int>& arr, int divisor, int threshold){
//     int cnt=0;
//     int n=arr.size();

//     for(int i=0;i<n;i++){
//         cnt+=(arr[i]+divisor-1)/divisor;
//     }
//     return(cnt<=threshold);
// }

// int smallestDivisor(vector<int>& arr, int threshold){
//     int n=arr.size();
//     int end=maxEl(arr);

//     for(int i=1;i<=end;i++){
//         if(possible(arr,i,threshold)){
//             return i;
//         }
//     }
//     return -1;
// }

//!BINARY SEARCH

int maxEl(vector<int>& arr){
    int n=arr.size();
    int maxi=0;

    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

bool possible(vector<int>& arr, int divisor, int threshold){
    int cnt=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        cnt+=(arr[i]+divisor-1)/divisor;
    }
    return cnt<=threshold;
}

int smallestDivisor(vector<int>& arr, int threshold){
    int low=1;
    int high=maxEl(arr);

    while(low<=high){
        int mid=(low+high)/2;

        if(possible(arr,mid,threshold)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return low;
}

int main(){
    vector<int> arr={1,2,5,9};
    int ans=smallestDivisor(arr,6);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 5";
return 0;
}