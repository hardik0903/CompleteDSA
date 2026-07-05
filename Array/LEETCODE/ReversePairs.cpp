#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE-FORCE APPROACH
// int ReversePairs(vector<int>& arr){
//     int n=arr.size();
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>2*arr[j]){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

//!OPTIMAL APPROACH

void merge(vector<int>& arr, int low, int mid, int high){
    int n=arr.size();
    int left=low;
    int right=mid+1;
    int index=0;
    vector<int> ans(high-low+1);

    while(left<=mid && right<=high){
        if(arr[left]>arr[right]){
            ans[index]=arr[right];
            index++;
            right++;
        }
        else{
            ans[index]=arr[left];
            index++;
            left++;
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
}

int countPairs(vector<int>& arr , int low, int mid, int high){
    int cnt=0;
    int n=arr.size();

    int j=mid+1;

    for(int i=low;i<=mid;i++){
        while(j<=high && arr[i]>(2*arr[j])){
            j++;
        }
        cnt+=(j-(mid+1));
    }
    return cnt;
}

int mergeSort(vector<int>& arr, int low, int high){
    int cnt=0;
    int n=arr.size();

    if(low<high){
        int mid=(low+high)/2;

        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=countPairs(arr,low,mid,high);
        merge(arr,low,mid,high);
    }
    return cnt;
}

int ReversePairs(vector<int>& arr){
    int n=arr.size();

    return (mergeSort(arr,0,n-1));
}

// void merge(vector<int>& arr,int low,int mid,int high){
//     int n=arr.size();
//     int left=low;
//     int right=mid+1;
//     vector<int> temp;

//     while(left<=mid && right<=high){
//         if(arr[left]<arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else{
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     while(left<=mid){
//         temp.push_back(arr[left]);
//         left++;
//     }

//     while(right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for(int i=low;i<=high;i++){
//         arr[i]=temp[i-low];
//     }

// }

// int countPairs(vector<int>& arr,int low,int mid,int high){
//     int n=arr.size();
//     int cnt=0;
//     int right=mid+1;
//     for(int i=low;i<=mid;i++){
//         while(right<=high && arr[i]>2*arr[right]){
//             right++;
//             cnt+=(right-(mid+1));
//         }
//     }
//     return cnt;
// }

// int mergeSort(vector<int>& arr,int low,int high){
//     if(low>=high) return 0;
//     int cnt=0;

//     int mid=((low+high)/2);
//     cnt+=mergeSort(arr,low,mid);
//     cnt+=mergeSort(arr,mid+1,high);
//     cnt+=countPairs(arr,low,mid,high);
//     merge(arr,low,mid,high);

//     return cnt;
// }

// int ReversePairs(vector<int>& arr){
//     int n=arr.size();
//     return mergeSort(arr,0,n-1);
// }

int main(){

    vector<int> arr1={1,3,2,3,1};
    int answer=ReversePairs(arr1);

    cout<<"Calaculated Answer is: "<<answer<<" Whereas Real Answer is: 2";

return 0;
}