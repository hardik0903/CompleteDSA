#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

//!LINEAR SEARCH
// bool studentsCounter(vector<int>& arr, int pages, int students){
//     int cntStudents=1;
//     int currentPages=0;
//     int n=arr.size();

//     for(int i=0;i<n;i++){
//         if(currentPages+arr[i]<=pages){
//             currentPages+=arr[i];
//         }
//         else{
//             cntStudents++;
//             currentPages=arr[i];
//         }
//     }
    
//     return (cntStudents<=students);
// }

// int AllocateBooks(vector<int>& arr, int m){
//     int low=*max_element(arr.begin(),arr.end());
//     int high=accumulate(arr.begin(),arr.end(),0);
//     int ans=INT_MAX;

//     for(int i=low;i<=high;i++){
//         if(studentsCounter(arr,i,m)){
//             ans=min(i,ans);
//         }
//     }

//     return ans;
// }

//!USING BINARY SEARCH
bool studentsCounter(vector<int>& arr, int pages, int students){
    int cntStudents=1;
    int currentPages=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        if(currentPages+arr[i]<=pages){
            currentPages+=arr[i];
        }
        else{
            cntStudents++;
            currentPages=arr[i];
        }
    }
    
    return (cntStudents<=students);
}

int AllocateBooks(vector<int>& arr, int m){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid=(low+high)/2;

        if(studentsCounter(arr,mid,m)){
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
    int ans=AllocateBooks(arr,4);

    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 71";
return 0;
}