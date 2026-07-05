#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//!BRUTE-FORCE APPROACH
// bool SearchIn2DMatrix(vector<vector<int>>& arr, int target){
//     int n=arr.size();
//     int m=arr[0].size();

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(arr[i][j]==target){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

//!BETTER APPROACH
// bool binarySearch(vector<int>& arr, int n, int target){
//     int low=0;
//     int high=n;

//     while(low<=high){
//         int mid=(low+high)/2;

//         if(arr[mid]==target){
//             return true;
//         }
//         else if(arr[mid]<target){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return false;
// }

// bool SearchIn2DMatrix(vector<vector<int>>& arr, int target){
//     int n=arr.size();
//     int m=arr[0].size();

//     for(int i=0;i<n;i++){
//         if(arr[i][0]<=target && target<=arr[i][m-1]){
//             return binarySearch(arr[i],m, target);
//         }
//     }

//     return false;
// }

//!OPTIMAL APPROACH
bool SearchIn2DMatrix(vector<vector<int>>& arr, int target){
    int n=arr.size();
    int m=arr[0].size();
    int low=0;
    int high=(n*m-1);

    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;

        if(arr[row][col]==target){
            return true;
        }
        else if(arr[row][col]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> arr={
        {1,2,3,4,5},
        {6,12,13,14,15},
        {20,23,24,29,32}
    };

    bool ans=SearchIn2DMatrix(arr,23);

    cout<<" Calculated Answer is: "<<ans<<" Whereas Real Answer is: 1";
return 0;
}