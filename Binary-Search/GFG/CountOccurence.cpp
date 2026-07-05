#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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

int countOccurence(vector<int>& arr,int target){
    vector<int> ans=searchRange(arr,target);
    if(ans[0]==-1) return 0;
    return (ans[1]-ans[0]+1);
}

int main()
{

    vector<int> arr = {2, 8, 8, 8, 8, 8, 11, 13};
    int ans = countOccurence(arr, 8);
    cout << "Calculated Answer is: "<<ans<<" Whereas Real Answer is: 5";
return 0;
}