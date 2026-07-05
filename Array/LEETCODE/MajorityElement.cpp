#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

//!BRUTE-FORCE APPROACH
// int MajorityElement(vector<int>& arr){
//     int n=arr.size();
//     int element;

//     for(int i=0;i<n;i++){
//         int count=0;
//         for(int j=0;j<n;j++){
//             if(arr[j]==arr[i]){
//                 count++;
//             }
//             if(count>(n/2)){
//                 return arr[i];
//             }
//         }
//     }
//     return -1;
// }

//!BETTER APPROACH
// int MajorityElement(vector<int>& arr){
//     int n=arr.size();
//     map<int,int> mpp;

//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//     }

//     for(auto it:mpp){
//         if(it.second > (n/2)){
//             return it.first;
//         }
//     }

//     return -1;
// }

//!OPTIMAL APPROACH
int MajorityElement(vector<int>& arr){
    int n=arr.size();
    int count=0;
    int el;

    for(int i=0;i<n;i++){
        if(count==0){
            el=arr[i];
            count=1;
        }
        if(arr[i]=el){
            count++;
        }
        else{
            count--;
        }
    }

    int count1=0;
    for(int i=0;i<n;i++){
        if(arr[i]=el){
            count1++;
        }
        if(count1>(n/2)){
            return el;
        }
    }
    return -1;
}

int main(){
    vector<int> arr={2,2,1,1,1,2,2};
    int answer=MajorityElement(arr);
    cout<<"Calculated Answer is: "<<answer<<" Whereas Real Answer is: 2";
return 0;
}