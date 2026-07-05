#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<int> MaximumSubarray(vector<int>& arr){
    int n=arr.size();
    int sum=0;
    int maxi=INT_MIN;
    int start=0;
    int end=0;
    int tempStart=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            start=tempStart;
            end=i;
        }
        if(sum<0){
            sum=0;
            tempStart=i+1;
        }
    }
    return vector<int> (arr.begin()+start, arr.begin()+end+1);
}

int main(){
    vector<int> arr={-1,-2,4,5,-1,-3,5};
    vector<int> ans=MaximumSubarray(arr);
    int n=ans.size();
    cout<<"Calculated Answer is: ";
    for(int num:ans){
        cout<<num<<" ";
    }
    cout<<" Whereas Real Answer is: 4, 5, -1, -3, 5";
return 0;
}