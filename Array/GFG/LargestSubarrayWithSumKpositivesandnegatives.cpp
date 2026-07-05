#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <map>

using namespace std;

//! BRUTE FORCE APPROACH
// int LargestSubarray(vector<int>& arr,int d){
//     int n=arr.size();
//     int maxi=0;

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum+=arr[k];
//             }
//             if(sum==d){
//                 maxi=max(maxi,j-i+1);
//             }
//         }
//     }

//     return maxi;
// }

//! BETTER APPROACH
// int LargestSubarray(vector<int>& arr,int k){
//     int n=arr.size();
//     int maxi=0;

//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             if(sum==k){
//                 maxi=max(maxi,j-i+1);
//             }
//         }
//     }

//     return maxi;
// }

//! OPTIMAL APPROACH USING HASHING
int LargestSubarray(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int, int> mpp;
    int preSum = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];

        if (preSum == k)
        {
            maxi = max(maxi, i + 1);
        }
        int rem = preSum - k;
        if (mpp.find(rem) != mpp.end())
        {
            maxi = max(maxi, i - mpp[rem]);
        }
        if(mpp.find(preSum) == mpp.end())
        {
            mpp[preSum] = i;
        }
    }

    return maxi;
}

int main()
{

    vector<int> arr1 = {10, 5, 2, 7, 1, -10};
    vector<int> arr2 = {-5, 8, -14, 2, 4, 12};

    int largestarray1 = LargestSubarray(arr1, 15);
    int largestarray2 = LargestSubarray(arr2, -5);

    cout << "Answer is: " << largestarray1 << " Whereas real answer is: 6" << endl;
    cout << "Answer is: " << largestarray2 << " Whereas real answer is: 5" << endl;

    return 0;
}