#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;


//!BRUTE-FORCE APPROACH
// vector<int> MajorityElement(vector<int> arr){
//     int n=arr.size();
//     vector<int> ans;

//     for(int i=0;i<n;i++){
//         if(ans.size()==0 || ans[0]!=arr[i]){
//             int cnt=0;
//             for(int j=0;j<n;j++){
//                 if(arr[j]==arr[i]){
//                     cnt++;
//                 }
//             }
//             if(cnt>(n/3)){
//                 ans.push_back(arr[i]);
//             }
//         }
//         if(ans.size()==2){
//             break;
//         }
//     }
//     return ans;
// }

//!BETTER APPROACH
// vector<int> MajorityElement(vector<int> arr){
//     int n=arr.size();

//     map<int,int> mpp;
//     vector<int> ans;
//     int required=(n/3);

//     for(int i=0;i<n;i++){
//         mpp[arr[i]]++;
//         if(mpp[arr[i]]>required){
//             ans.push_back(arr[i]);
//         }
//     }
//     return ans;
// }

//!OPTIMAL APPROACH
vector<int> MajorityElement(vector<int>& arr){
    int n=arr.size();
    int el1=INT_MIN;
    int el2=INT_MIN;
    int count1=0;
    int count2=0;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(count1==0 && el2!=arr[i]){
            el1=arr[i];
            count1++;
        }
        if(count2==0 && el1!=arr[i]){
            el2=arr[i];
            count2++;
        }
        else if(arr[i]==el1){
            count1++;
        }
        else if(arr[i]==el2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    count1=0;
    count2=0;
    int required=(int)(n/3)+1;
    for(int i=0;i<n;i++){
        if(arr[i]==el1){
            count1++;
        }
        if(arr[i]==el2){
            count2++;
        }
    }

    if(count1>=required){
        ans.push_back(el1);
    }
    if(count2>=required){
        ans.push_back(el2);
    }
    return ans;
}


int main(){
    vector<int> arr={1,1,1,3,3,2,2,2};

    vector<int> ans=MajorityElement(arr);

    int n=ans.size();

    cout<<"Calculated Answer is: ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<" Whereas Real Answer is: [1,2]";
return 0;
}