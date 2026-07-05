#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!LINEAR SEARCH
// int sumEl(vector<int>& arr){
//     int n=arr.size();
//     int totalSum=0;
//     for(int i=0;i<n;i++){
//         totalSum+=arr[i];
//     }
//     return totalSum;
// }

// int daysCalculator(vector<int>& arr, int capacity){
//     int days=1;
//     int n=arr.size();
//     int load=0;

//     for(int i=0;i<n;i++){
//         if(load+arr[i]>capacity){
//             days+=1;
//             load=arr[i];
//         }
//         else{
//             load+=arr[i];
//         }
//     }

//     return days;
// }
// int shipWithinDays(vector<int>& arr, int days){
//     int n=arr.size();
//     int end=sumEl(arr);

//     for(int i=0;i<=end;i++){
//         int nofdays=daysCalculator(arr,i);
//         if(nofdays<=days){
//             return i;
//         }
//     }
//     return -1;
// }


//!BINARY SEARCH
int maxEl(vector<int>& arr){
    int n=arr.size();
    int maxi=0;

    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

int sumEl(vector<int>& arr){
    int n=arr.size();
    int totalSum=0;

    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    return totalSum;
}

int CalculateDays(vector<int> arr, int capacity){
    int days=1;
    int load=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        if(load+arr[i]>capacity){
            days+=1;
            load=arr[i];
        }
        else{
            load+=arr[i];
        }
    }

    return days;
}

int shipWithinDays(vector<int> arr, int days){
    int low=maxEl(arr);
    int high=sumEl(arr);

    while(low<=high){
        int mid=(low+high)/2;
        int nofdays=CalculateDays(arr,mid);
        if(nofdays<=days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int ans=shipWithinDays(arr,5);
    cout<<"Calculated Answer is: "<<ans<<" Whereas Real Answer is: 15";
return 0;
}