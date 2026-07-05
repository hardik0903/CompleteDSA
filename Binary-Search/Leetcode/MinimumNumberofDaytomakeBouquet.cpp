#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE-FORCE APPROACH
// int minimuminArray(vector<int>& arr){
//     int mini=INT_MAX;
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         mini=min(mini,arr[i]);
//     }
//     return mini;
// }

// int maximuminArray(vector<int>& arr){
//     int maxi=INT_MIN;
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         maxi=max(maxi,arr[i]);
//     }
//     return maxi;
// }

// bool possible(vector<int>& arr,int d,int m, int k){
//     int n=arr.size();
//     int cnt=0;
//     int bouquet=0;

//     for(int i=0;i<n;i++){
//         if(arr[i]<=d) cnt++;
//         else{
//             bouquet+=(cnt/k);
//             cnt=0;
//         }
//     }
//     bouquet+=(cnt/k);
//     return (bouquet>=m);
// }

// int minimumDays(vector<int>& arr,int m, int k){
//     int low=minimuminArray(arr);
//     int high=maximuminArray(arr);

//     if((long)m*k > arr.size()){
//         return -1;
//     }
//     for(int i=low;i<=high;i++){
//         if(possible(arr,i,m,k)) return i;
//     }
//     return -1;
// }

//!OPTIMAL APPROACH USING BS

int maxEl(vector<int>& arr){
    int n=arr.size();
    int maxi=0;

    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}

int minEl(vector<int>& arr){
    int n=arr.size();
    int mini=INT_MAX;

    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
    }
    return mini;
}

int possible(vector<int>& arr, int days, int m, int k){
    int n=arr.size();
    int cnt=0;
    int bouquet=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=days) cnt++;
        else{
            bouquet+=(cnt/k);
            cnt=0;
        }
    }
    bouquet+=(cnt/k);
    return (bouquet>=m);
}

int minimumDays(vector<int>& arr, int m, int k){
    int low=minEl(arr);
    int high=maxEl(arr);

    while(low<=high){
        int mid=(low+high)/2;
        
        if(possible(arr,mid,m,k)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return low;
}

int main(){
    vector<int> arr={7,7,7,7,13,11,12,7};
    int answer=minimumDays(arr,2,3);

    cout<<"Calculated Answer is: "<<answer<<" Whereas real Answer is: 12";
return 0;
}