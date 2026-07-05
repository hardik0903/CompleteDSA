#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//!BRUTE-FORCE APPROACH
// bool Searchin2DMatrix2(vector<vector<int>>& arr, int target){
//     int n=arr.size();
//     int m=arr[0].size();

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(target==arr[i][j]){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//!BETTER APPROACH
// int binarySearch(vector<int>& arr, int target){
//     int low=0;
//     int high=arr.size();
//     int ans=-1;

//     while(low<=high){
//         int mid=(low+high)/2;

//         if(arr[mid]==target){
//             ans=mid;
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return ans;
// }
// bool Searchin2DMatrix2(vector<vector<int>>& arr, int target){
//     int n=arr.size();
//     int m=arr[0].size();

//     for(int i=0;i<n;i++){
//         int index=binarySearch(arr[i],target);
//         if(index!=-1){
//             return true;
//         }
//     }
//     return false;
// }

//!OPTIMAL APPROACH
bool Searchin2DMatrix2(vector<vector<int>>& arr, int target){
    int n=arr.size();
    int m=arr[0].size();
    int row=0, col=m-1;

    while(row<n && col>=0){
        if(arr[row][col]==target){
            return true;
        }
        else if(arr[row][col]<target){
            row++;
        }
        else{
            col--;
        }
    }
    return false;
}

int main(){

    vector<vector<int>> arr={
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    bool ans=Searchin2DMatrix2(arr,14);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 1";
return 0;
}