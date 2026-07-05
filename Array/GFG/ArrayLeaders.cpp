#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void reverse(vector<int>& arr){
    int n=arr.size();
    int j=n-1;
    int i=0;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;

        i++;
        j--;
    }
}

//!BRUTE FORCE CODE
// vector<int> Leaders(vector<int>& arr){
//     int n=arr.size();
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         bool leader=true;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]>arr[i]){
//                 leader=false;
//             }
//         }
//     if(leader==true){
//         ans.push_back(arr[i]);
//     }
//     }
//     return ans;
// }

//!OPTIMAL CODE
vector<int> Leaders(vector<int>& arr){
    int n=arr.size();
    int maxi=INT_MIN;
    vector<int> ans;

    for(int i=n-1;i>=0;i--){
        if(maxi<arr[i]){
            ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);
    }
    reverse(ans);
    return ans;
}

int main(){

    vector<int> arr1={16,17,4,3,5,2};

    vector<int> ans1=Leaders(arr1);
    int n=ans1.size();

    cout<<"Answer is: ";

    for(int i=0;i<n;i++){
        cout<<ans1[i]<<" ";
    }

    cout<<"Correct Answer is: 17,5,2"<<endl;

}