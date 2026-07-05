#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <map>

using namespace std;


//!BRUTE FORCE APPROACH
// int LargestSubarray(vector<int>& arr){
//     int n=arr.size();
//     int maxi=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum+=arr[k];
//             }
//             if(sum==0){
//                 maxi=max(maxi,j-i+1);
//             }
//         }
//     }

//     return maxi;
// }

//!BETTER APPROACH
// int LargestSubarray(vector<int>& arr){
//     int n=arr.size();
//     int maxi=0;

//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             if(sum==0){
//                 maxi=max(maxi,j-i+1);
//             }
//         }
//     }

//     return maxi;
// }

//!OPTIMAL APPROACH USING HASHING
int LargestSubarray(vector<int>& arr){
    int n=arr.size();
    int maxCnt=0;
    int sum=0;
    map<int,int> mpp;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==0){
            maxCnt=i+1;
        }
        if(mpp.find(sum)!=mpp.end()){
            maxCnt=max(maxCnt,i-mpp[sum]);
        }
        else{
            mpp[sum]=i;
        }
    }
    return maxCnt;
}

int main(){

    vector<int> arr1={15, -2, 2, -8, 1, 7, 10, 23};
    vector<int> arr2={-42,12,20,15,31,-4,0,15};

    int largestarray1=LargestSubarray(arr1);
    int largestarray2=LargestSubarray(arr2);


    cout<<"Answer is: "<<largestarray1<<" Whereas real answer is: 5"<<endl;
    cout<<"Answer is: "<<largestarray2<<" Whereas real answer is: 1"<<endl;

return 0;
}