#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int Floor(int target, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] <= target)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int Ceil(int target, vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= target)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> getFloorAndCeil(int target, vector<int> &arr)
{
    // code here
    int floor = Floor(target, arr);
    int ceil = Ceil(target, arr);

    return {floor, ceil};
}

int main(){

    vector<int> arr1={80,59,26,46};
    vector<int> ans=getFloorAndCeil(28,arr1);
    int n=ans.size();
    cout<<"Calculated Answer is: ";

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
    cout<<" Whereas Real Answer is: 26,46";
}