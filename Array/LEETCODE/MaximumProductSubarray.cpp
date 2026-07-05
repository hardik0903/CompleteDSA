#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE-FORCE APPROACH
// int MaximumProduct(vector<int> arr){
//     int n=arr.size();
//     int maxi=INT_MIN;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             int product =1;
//             for(int k=i;k<=j;k++){
//                 product*=arr[k];
//             }
//             maxi=max(maxi,product);
//         }
//     }
//     return maxi;
// }

//!BETTER APPROACH
// int MaximumProduct(vector<int> arr){
//     int n=arr.size();
//     int maxi=INT_MIN;

//     for(int i=0;i<n;i++){
//         int product =1;
//         for(int j=i;j<n;j++){
//             product*=arr[j];
//             maxi=max(maxi,product);
//         }
//     }
//     return maxi;
// }

//!OPTIMAL APPROACH
int MaximumProduct(vector<int>& arr){
    int n=arr.size();
    int prefix_Sum=1;
    int suffix_Sum=1;
    int maxi=0;

    for(int i=0;i<n;i++){

        prefix_Sum*=arr[i];
        suffix_Sum*=arr[n-i-1];

        if(prefix_Sum==0) prefix_Sum=1;
        if(suffix_Sum==0) suffix_Sum=1;

        maxi=max(maxi,max(prefix_Sum,suffix_Sum));
    }
    return maxi;
}

int main(){

    vector<int> arr1={2,3,-2,4};
    int answer=MaximumProduct(arr1);

    cout<<"Calculated answer is: "<<answer<<" Whereas real answer is:6";
return 0;
}