#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int LowerBound(vector<int>& arr,int target){
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

    vector<int> arr1={3,5,8,15};
    int answer1=LowerBound(arr1,8);

    cout<<"Calculated Answer is: "<<answer1<<" Whereas Real Answer is: 2"<<endl;;

    vector<int> arr2={1,3,5,7,9,9,9,9,10};
    int answer2=LowerBound(arr2,9);

    cout<<"Calculated Answer is: "<<answer2<<" Whereas Real Answer is: 4"<<endl;

    vector<int> arr3={1,3,5,7,9,10,12};
    int answer3=LowerBound(arr3,14);

    cout<<"Calculated Answer is: "<<answer3<<" Whereas Real Answer is: 7"<<endl;

    vector<int> arr4={2,3,4,5,6,7};
    int answer4=LowerBound(arr4,1);

    cout<<"Calculated Answer is: "<<answer4<<" Whereas Real Answer is: 0"<<endl;
return 0;
}
