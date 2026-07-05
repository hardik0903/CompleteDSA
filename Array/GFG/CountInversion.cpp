#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE FORCE APPROACH
// int numberOfInversion(vector<int>& arr){
//     int n=arr.size();
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 cnt++;
//             }
//         }
//     }

//     return cnt;
// }

//!OPTIMAL APPROACH
int merge(vector<int>& arr, int low, int mid, int high){
    int cnt=0;
    int n=arr.size();
    int left=low;
    int right=mid+1;
    vector<int> ans(high-low+1);
    int index=0;

    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            ans[index]=arr[left];
            left++;
            index++;
        }
        else{
            cnt+=(mid-left+1);
            ans[index]=arr[right];
            right++;
            index++;
        }
    }

    while(left<=mid){
        ans[index]=arr[left];
        left++;
        index++;
    }
    
    while(right<=high){
        ans[index]=arr[right];
        right++;
        index++;
    }


    for(int i=low;i<=high;i++){
        arr[i]=ans[i-low];
    }

    return cnt;
}


int mergeSort(vector<int>& arr, int low, int high){
    int cnt=0;
    if(low<high){
        int mid=(low+high)/2;
        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
    }
    return cnt;
}

int numberOfInversion(vector<int>& arr){
    int n=arr.size();

    return mergeSort(arr,0,n-1);
}


int main(){

    vector<int> arr1={5,3,2,4,1};
    int answer=numberOfInversion(arr1);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 8";

return 0;
}