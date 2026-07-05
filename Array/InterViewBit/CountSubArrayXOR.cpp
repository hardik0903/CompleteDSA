#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

//!BRUTEFORCE APPROACH
// int CountSubArray(vector<int>& arr,int ans){
//     int n=arr.size();
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int xr=0;
//             for(int k=i;k<=j;k++){
//                 xr^=arr[k];
//             }
//             if(xr==ans){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

//!BETTER APPROACH
// int CountSubArray(vector<int>& arr,int ans){
//     int n=arr.size();
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         int xr=0;
//         for(int j=i;j<n;j++){
//             xr^=arr[j];
//             if(xr==ans){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

//!OPTIMAL APPROACH
int CountSubArray(vector<int>& arr,int ans){
    int n=arr.size();
    int xr=0;
    int cnt=0;
    map<int,int> mpp;
    mpp[0]=1;

    for(int i=0;i<n;i++){
        xr^=arr[i];
        int x=xr^ans;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    vector<int> arr1={4,2,2,6,4};
    int answer=CountSubArray(arr1,6);
    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 4";
return 0;
}