#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

//!BRUTE-FORCE APPROACH
// int maximumofArray(vector<int>& arr){
//     int n=arr.size();
//     int maxEl=INT_MIN;
//     for(int i=0;i<n;i++){
//         maxEl=max(maxEl,arr[i]);
//     }
//     return maxEl;
// }

// int speedofEating(vector<int>& arr,int hourly){
//     int n=arr.size();
//     int hrs=0;
//     for(int i=0;i<n;i++){
//         hrs+=ceil((double)arr[i]/(double)hourly);
//     }
//     return hrs;
// }

// int minimumRate(vector<int>& arr,int h){
//     int n=arr.size();
//     int maxEl=maximumofArray(arr);
//     for(int i=1;i<=maxEl;i++){
//         int speed=speedofEating(arr,i);
//         if(speed<=h){
//             return i;
//         }
//     }
//     return maxEl;
// }


//!OPTIMAL APPROACH USING BS
bool possible(vector<int>& arr, int k, int h){
    long long hours=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        int div=(arr[i]/k);
        hours+=div;
    }
    if(hours%k!=0) hours++;

    return (hours<=h);
}

int minimumRate(vector<int>& arr, int h){
    int n=arr.size();
    int low=1;
    int high=1000000000;

    while(low<=high){
        int mid=(low+high)/2;

        if(possible(arr,mid,h)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr={3,6,7,11};
    int answer=minimumRate(arr,8);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 4";
return 0;
}