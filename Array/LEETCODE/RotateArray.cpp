#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//!BRUTE-FORCE APPROACH
// void rotateArr(vector<int>& arr, int d){
//     int n=arr.size();
//     vector<int> ans(n);

//     for(int i=0;i<n;i++){
//         ans[(i+d)%n]=arr[i];
//     }

//     for(int i=0;i<n;i++){
//         arr[i]=ans[i];
//     }
// }

//!OPTIMAL APPROACH
void reverse(vector<int>& arr,int l,int r){
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

void rotateArr(vector<int>& arr, int d){
    int n=arr.size();
    if(d==0){
        return;
    }
    reverse(arr,0,n-1);
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
}

int main(){

    vector<int> arr={1,2,3,4,5};
    int k=2;
    rotateArr(arr,k);
    int n=arr.size();
    cout<<"Calculate Answer is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Whereas Real Answer is: 4,5,1,2,3";
return 0;
}