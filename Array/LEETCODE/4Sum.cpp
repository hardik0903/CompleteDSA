#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;

//! BRUTE-FORCE APPROACH
// vector<vector<int>> FourSum(vector<int>& arr,int target){

//     int n=arr.size();
//     vector<vector<int>> ans;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 for(int l=k+1;l<n;l++){
//                     long long sum=arr[i]+arr[j];
//                     sum+=arr[k];
//                     sum+=arr[l];

//                     if(sum==target){
//                         vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
//                         sort(temp.begin(),temp.end());
//                         ans.push_back(temp);
//                     }
//                 }
//             }
//         }
//     }
//     return ans;
// }

//! BETTER APPROACH

//! Approach with Set
// vector<vector<int>> FourSum(vector<int>& arr,int target){
//     int n=arr.size();
//     set<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             set<long long> hashset;
//             for(int k=j+1;k<n;k++){
//                 int sum=arr[i]+arr[j];
//                 sum+=arr[k];
//                 int fourth=target-sum;
//                 if(hashset.find(fourth)!=hashset.end()){
//                     vector<int> temp={arr[i],arr[j],arr[k],fourth};
//                     sort(temp.begin(),temp.end());
//                     ans.insert(temp);
//                 }
//                 hashset.insert(arr[k]);
//             }
//         }
//     }
//     vector<vector<int>> finalAnswer(ans.begin(),ans.end());
//     return finalAnswer;
// }

//! Approach without Set
// vector<vector<int>> FourSum(vector<int>& arr,int target){
//     int n=arr.size();
//     vector<vector<int>> ans;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             set<long long> hashset;
//             for(int k=j+1;k<n;k++){
//                 int sum=arr[i]+arr[j];
//                 sum+=arr[k];
//                 int fourth=target-sum;
//                 if(hashset.find(fourth)!=hashset.end()){
//                     vector<int> temp={arr[i],arr[j],arr[k],fourth};
//                     sort(temp.begin(),temp.end());
//                     ans.push_back(temp);
//                 }
//                 hashset.insert(arr[k]);
//             }
//         }
//     }
//     return ans;
// }

//! OPTIMAL APPROACH
vector<vector<int>> FourSum(vector<int>& arr,int target){

    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(arr[i]==arr[i-1] && i>0){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j]==arr[j-1] && j>i+1){
                continue;
            }

            int k=j+1;
            int l=n-1;

            while(k<l){
                int sum=arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];

                if(sum==target){
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);

                    k++;
                    l--;

                    while(arr[k]==arr[k-1] && k<l){
                        k++;
                    }
                    while(arr[l]==arr[l+1] && k<l){
                        l--;
                    }
                }

                else if(sum>target){
                    l--;
                }

                else{
                    k++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> answer = FourSum(arr1, 0);

    cout << "Calculated Answer is: " << endl;
    for (const auto &row : answer)
    {
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "\n";
    }

    cout << "Whereas Real Answer is:  [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]"<<endl;

    vector<int> arr2 = {1,1,1,2,2,2,3,3,3,4,4,4,5,5};
    vector<vector<int>> answer2 = FourSum(arr2, 8);

    cout << "Calculated Answer is: " << endl;
    for (const auto &row : answer2)
    {
        for (const auto &element : row)
        {
            cout << element << " ";
        }
        cout << "\n";
    }

    cout << "Whereas Real Answer is:  [[1,1,1,5],[1,1,2,4],[1,1,3,3]]"<<endl;
}