#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//!BRUTE-FORCE APROACH
// int missingNumber(vector<int>& arr, int k){
//     int n=arr.size();
//     vector<int> MissingNumberStored;

//     for(int i=1;i<=1000;i++){
//         if(find(arr.begin(), arr.end(), i) == arr.end()){
//             MissingNumberStored.push_back(i);
//         }
//     }

//     int n2=MissingNumberStored.size();

//     for(int i=0;i<n2;i++){
//         if(i==(k-1)){
//             return MissingNumberStored[i];
//         }
//     }

//     return -1;
// }

//!BETTER APPROACH
// int missingNumber(vector<int> arr, int k){
//     int n=arr.size();

//     for(int i=0;i<n;i++){
//         if(arr[i]<=k){
//             k++;
//         }
//         else{
//             break;
//         }
//     }

//     return k;
// }

//!OPTIMAL APPROACH
int missingNumber(vector<int> arr, int k){
    int n=arr.size();
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        
        if(missing<k){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return k+low;
}

int main(){

    vector<int> arr={2,3,4,7,11};
    int ans=missingNumber(arr,5);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 9";
return 0;
}