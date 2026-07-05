#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//!BRUTE-FORCE APPROACH
// int findMaxOnes(vector<vector<int>>& arr, int n, int m){
//     int index=-1;
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         int cntOnes=0;
//         for(int j=0;j<m;j++){
//             cntOnes+=arr[i][j];
//             if(cntOnes>cnt){
//                 cnt=cntOnes;
//                 index=i;
//             }
//         }
//     }
//     return index;
// }

//!OPTIMAL APPROACH USING BINARY SEARCH
int lower_bound(vector<int>& arr, int n, int k){
    int low=0;
    int high =n-1;
    int ans=n;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int findMaxOnes(vector<vector<int>>& arr, int n, int m){
    int cnt=0;
    int index=-1;

    for(int i=0;i<n;i++){
        int cntOnes=m-lower_bound(arr[i],m,1);
        if(cntOnes>cnt){
            cnt=cntOnes;
            index=i;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> arr={
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    };

    vector<vector<int>> arr2={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int ans=findMaxOnes(arr,5,5);
    int ans2=findMaxOnes(arr2,5,5);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 2"<<endl;
    cout<<"Calculated Answer is: "<<ans2<<" Whereas Real Answer is: -1"<<endl;
return 0;
}