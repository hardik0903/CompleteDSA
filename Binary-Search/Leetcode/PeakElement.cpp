#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE-FORCE APPROACH
// int PeakElement(vector<int>& arr){
//     int n=arr.size();

//     for(int i=0;i<n;i++){
//         if((i==0 || arr[i]>arr[i+1]) && (i==n-1 || arr[i]>arr[i+1])){
//             return i;
//         }
//     }
//     return -1;
// }

//!OPTIMAL APPROACH
int PeakElement(vector<int>& arr){
    int n=arr.size();

    if(n==0) return 0;

    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;

    int low=1;
    int high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }

        else if(arr[mid]>arr[mid-1]){
            low=mid+1;
        }

        else if(arr[mid]>arr[mid+1]){
            high=mid-1;
        }

        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int> arr={1,2,3,4,5,6,7,8,9,5,6,7,8,9};
    int answer=PeakElement(arr);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer can be: 8,13";
return 0;
}