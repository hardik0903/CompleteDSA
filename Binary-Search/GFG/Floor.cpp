#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int Floor(vector<int>& arr,int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]<=target){
            ans=arr[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr1={3,5,8,15};
    int answer1=Floor(arr1,9);

    cout<<"Calculated Answer is: "<<answer1<<" Whereas Real Answer is: 8"<<endl;;

    vector<int> arr2={1,3,5,7,9,9,9,9,10};
    int answer2=Floor(arr2,9);

    cout<<"Calculated Answer is: "<<answer2<<" Whereas Real Answer is: 9"<<endl;

    vector<int> arr3={1,3,5,7,9,10,12};
    int answer3=Floor(arr3,14);

    cout<<"Calculated Answer is: "<<answer3<<" Whereas Real Answer is: 12"<<endl;

    vector<int> arr4={2,3,4,5,6,7};
    int answer4=Floor(arr4,1);

    cout<<"Calculated Answer is: "<<answer4<<" Whereas Real Answer is: -1"<<endl;
return 0;
}
