#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

//! BRUTE-FORCE APPROACH(APPROACH -I BACKTRACKING APPROACH)
// vector<vector<int>> permute(vector<int>& arr){
    
//     vector<vector<int>> res;

//     if(arr.size()==1){
//         vector<int> singleList;
//         singleList.push_back(arr[0]);
//         res.push_back({singleList[0]});
//         return res;
//     }

//     for(int i=0;i<arr.size();i++){
//         int n=arr[i];
//         vector<int> remainingNumber;
//         for(int j=0;j<arr.size();j++){
//             if(j!=i){
//                 remainingNumber.push_back(arr[j]);
//             }
//         }

//         vector<vector<int>> perms=permute(remainingNumber);

//         for(vector<int> p: perms){
//             p.insert(p.begin(),arr[i]);
//             res.push_back(p);
//         }
//     }
//     return res;
// }

// void NextPermutation(vector<int>& arr){
//     int n=arr.size();
//     vector<vector<int>> allPermutation=permute(arr);

//     for(int i=0;i<allPermutation.size();++i){
//         if(arr==allPermutation[i]){
//             if(i==allPermutation.size()-1){
//                 arr=allPermutation[0];
//             }
//             else{
//                 arr=allPermutation[i+1];
//             }
//             return;
//         }
//     }
// }

//!BRUTE-FORCE APPROACH(APPROACH -II SWAPING APPROACH)
// void recurPermute(int index,vector<int>& arr,vector<vector<int>>& ans){
//     if(index==arr.size()){
//         ans.push_back(arr);
//         return;
//     }

//     for(int i=index;i<arr.size();i++){
//         swap(arr[index],arr[i]);
//         recurPermute(index+1,arr,ans);
//         swap(arr[index],arr[i]);
//     }
// }

// vector<vector<int>> permute(vector<int>& arr){
//     vector<vector<int>> ans;
//     recurPermute(0,arr,ans);
//     return ans;
// }

// void NextPermutation(vector<int>& arr){
//     vector<vector<int>> allPermutation=permute(arr);

//     for(int i=0;i<allPermutation.size();++i){
//         if(arr==allPermutation[0]){
//             if(i==allPermutation.size()-1){
//                 arr=allPermutation[0];
//             }
//             else{
//                 arr=allPermutation[i+1];
//             }
//             return;
//         }
//     }
// }

void NextPermutation(vector<int>& arr){
    int n=arr.size();

    int ind=-1;

    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }

    if(ind==-1){
        reverse(arr.begin(),arr.end());
    }

    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }

    reverse(arr.begin()+ind+1,arr.end());
}
int main()
{

    vector<int> arr = {1, 2, 3};
    NextPermutation(arr);
    int n = arr.size();

    cout << "Calculated Answer is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " Whereas Real Answer is: 1 3 2";
    return 0;
}