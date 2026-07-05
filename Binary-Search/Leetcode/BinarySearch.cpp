#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int BinarySearch(vector<int>& arr, int target){
    int low=0;
    int high=arr.size()-1;

    while(low<=high){
        int mid=((low+high)/2);

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int> arr={1,2,3,4,5,6};
    int answer=BinarySearch(arr,6);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real answer is: 5";
return 0;
}