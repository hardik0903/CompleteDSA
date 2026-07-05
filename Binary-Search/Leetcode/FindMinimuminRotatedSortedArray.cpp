#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!NORMAL OPTIMAL SOLUTION
// int MinimumElement(vector<int>& arr){
//     int n=arr.size();
//     int low=0;
//     int high=n-1;
//     int ans=INT_MAX;

//     while(low<=high){
//         int mid=(low+high)/2;

//         if(arr[low]<=arr[mid]){
//             ans=min(ans,arr[low]);
//             low=mid+1;
//         }
//         else{
//             ans=min(ans,arr[mid]);
//             high=mid-1;
//         }
//     }
//     return ans;
// }

//!OPTIMIZED OPTIMAL SOLUTUON
int MinimumElement(vector<int>& arr){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;
}


int main(){

    vector<int> arr={4,5,6,7,0,1,2};
    int answer=MinimumElement(arr);

    vector<int> arr2={7,8,1,2,3,4,5,6};
    int answer2=MinimumElement(arr2);

    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 0"<<endl;
    cout<<"Calculated Answer is: "<<answer2<<" Whereas Real Answer is: 1"<<endl;

return 0;
}