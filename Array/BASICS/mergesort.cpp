#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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

void mergeSort(vector<int>& arr, int low, int high){
    int n=arr.size();

    if(low<high){
        int mid=(low+high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    vector<int> ans={3,4,23,34,32,14};
    int n=ans.size();
    mergeSort(ans,0,n-1);
    cout<<"Sorted Array is: ";

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
return 0;
}