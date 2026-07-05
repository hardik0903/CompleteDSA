#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE-FORCE APPROACH
// vector<int> searchRange(vector<int>& arr,int target){
//     int n=arr.size();
//     int first=-1;
//     int last=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i]==target){
//             if(first==-1){
//                 first=i;
//             }
//             last=i;
//         }
//     }
//     return {first,last};
// }

//! USING LOWER BOUND AND UPPER BOUND APPROACH
// int lowerbound(vector<int>& arr,int target){
//     int n=arr.size();
//     int low=0;
//     int high=n-1;
//     int first=-1;

//     while(low<=high){
//         int mid=((low+high)/2);
//         if(arr[mid]>=target){
//             first=mid;
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return first;
// }

// int upperbound(vector<int>& arr,int target){
//     int n=arr.size();
//     int low=0;
//     int high=n-1;
//     int last=-1;

//     while(low<=high){
//         int mid=((low+high)/2);
//         if(arr[mid]>target){
//             last=mid;
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return last;
// }

// vector<int> searchRange(vector<int>& nums, int target) {
//     int first=lowerbound(nums,target);
//     if(first==nums.size() || nums[first]!=target) return {-1,-1};
//     return {first,upperbound(nums,target)-1};
// }

//! USING RAW BINARY APPROACH
int firstOccurence(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurence(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int first = firstOccurence(nums, target);
    if (first == -1)
        return {-1, -1};
    return {first, lastOccurence(nums, target)};
}

int main()
{

    vector<int> arr = {2, 8, 8, 8, 8, 8, 11, 13};
    vector<int> ans = searchRange(arr, 8);
    int n = ans.size();
    cout << "Calculated Answer is: ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "Whereas Real Answer is: 1 5";
    return 0;
}