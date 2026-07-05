#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int SearchinSortedArray(vector<int>& arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==target){
            return mid;
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr={3,3,3,3,1,3,3,3,3};
    int answer=SearchinSortedArray(arr,1);
    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 4";
return 0;
}