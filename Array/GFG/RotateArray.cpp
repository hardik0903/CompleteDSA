#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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
    d=d%n;
    if(d==0){
        return;
    }

    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main(){

    vector<int> arr1={1,2,3,4,5};
    int k1=2;
    rotateArr(arr1,k1);
    int n1=arr1.size();
    cout<<"Calculate Answer is: ";
    for(int i=0;i<n1;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"Whereas Real Answer is: 3 4 5 1 2"<<endl;

    vector<int> arr2={2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int k2=3;
    rotateArr(arr2,k2);
    int n2=arr2.size();
    cout<<"Calculate Answer is: ";
    for(int i=0;i<n2;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<"Whereas Real Answer is: 8 10 12 14 16 18 20 2 4 6"<<endl;
return 0;
}