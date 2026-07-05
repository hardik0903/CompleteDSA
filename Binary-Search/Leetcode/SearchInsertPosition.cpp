#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int SearchInsertPosition(vector<int>& arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=n;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr1={1,3,5,6};
    int answer1=SearchInsertPosition(arr1,5);

    cout<<"Calculated Answer is: "<<answer1<<" Whereas Real Answer is: 2"<<endl;;

    vector<int> arr2={1,3,5,6};
    int answer2=SearchInsertPosition(arr2,2);

    cout<<"Calculated Answer is: "<<answer2<<" Whereas Real Answer is: 1"<<endl;

    
return 0;
}
