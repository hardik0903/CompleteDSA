#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int secondLargestElement(vector<int>& arr){
    int n=arr.size();
    int secondLargest=INT_MIN;
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]<largest){
            secondLargest=arr[i];
        }
    }

    return secondLargest;
}

int main(){

    vector<int> arr1={15,34,35,1,2,4};
    int secondLargest=secondLargestElement(arr1);

    cout<<"Answer is: "<<secondLargest<<" Whereas Real Answer is: 34";
return 0;
}