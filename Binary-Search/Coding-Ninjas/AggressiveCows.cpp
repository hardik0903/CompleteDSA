#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


// bool CowsPlace(vector<int>& arr, int assumedMinimumPlace, int cows){
//     int n=arr.size();
//     int cnt=1;
//     int last=arr[0];

//     for(int i=0;i<n;i++){
//         if(arr[i]-last>=assumedMinimumPlace){
//             cnt++;
//             last=arr[i];
//         }
//     }

//     return (cnt>=cows);
// }
// int MaxofMinDist(vector<int> arr, int cows){
//     int n=arr.size();
//     sort(arr.begin(),arr.end());
//     int maxi=arr[n-1];
//     int mini=arr[0];
//     int end=maxi-mini;
//     for(int i=1;i<=end;i++){
//         if(CowsPlace(arr,i,cows)){
//             continue;
//         }
//         else{
//             return i-1;
//         }
//     }
//     return -1;
// }

//!BINARY SEARCH APPROACH

bool CowsPlace(vector<int>& arr, int dist, int cows){
    int n=arr.size();
    int cowsCnt=1;
    int last=arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]-last>=dist){
            cowsCnt++;
            last=arr[i];
        }
    }

    return (cowsCnt>=cows);
}

int MaxofMinDist(vector<int>& arr, int cows){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int low=1;
    int high=arr[n-1];

    while(low<=high){
        int mid=(low+high)/2;

        if(CowsPlace(arr,mid,cows)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    vector<int> arr={0,3,4,7,9,10};
    int ans=MaxofMinDist(arr, 4);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 3";
return 0;
}

