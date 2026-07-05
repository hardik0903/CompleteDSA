#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void MoveZeroes(vector<int>& arr){
    int n=arr.size();
    int nonzero=0;

    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[nonzero++]=arr[i];
        }
    }
    while(nonzero<n){
        arr[nonzero++]=0;
    }
}

int main(){

    vector<int> arr1={1,0,2,0,3};
    MoveZeroes(arr1);
    int n=arr1.size();

    cout<<"Calculated Answer is: ";
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"Whereas Real Answer is: 1 2 3 0 0";
return 0;
}