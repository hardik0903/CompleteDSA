#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void ReverseArray(vector<int>& arr){
    int n=arr.size();
    int i=0;
    int j=n-1;

    while(i<=j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

        i++;
        j--;
    }
}

int main(){
    vector<int> arr={1,2,3,4};
    ReverseArray(arr);
    int n=arr.size();
    cout<<"Calculated Answer is: ";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<" Whereas Real Answer is: 4,3,2,1";
return 0;
}