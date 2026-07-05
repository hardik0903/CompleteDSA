#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//! BRUTE FORCE APPROACH
//  int pairWithMaxSum(vector<int>& arr){
//      int n=arr.size();
//      int max_score=0;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             int secondSmallest=INT_MAX;
//             int smallest=INT_MAX;
//             for(int k=i;k<=j;k++){
//                 if(arr[k]<smallest){
//                     secondSmallest=smallest;
//                     smallest=arr[k];
//                 }
//                 else if(arr[k]<secondSmallest){
//                     secondSmallest=arr[k];
//                 }
//             }
//             max_score=max(max_score,smallest+secondSmallest);
//         }
//     }
//     return max_score;
// }


//!BETTER APPROACH
// int pairWithMaxSum(vector<int> &arr)
// {
//     int n = arr.size();
//     int max_score = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int secondSmallest = INT_MAX;
//         int smallest = INT_MAX;
//         for (int j = i; j < n; j++)
//         {
//             if (arr[j] < smallest)
//             {
//                 secondSmallest = smallest;
//                 smallest = arr[j];
//             }
//             else if (arr[j] < secondSmallest)
//             {   
//                 secondSmallest = arr[j];
//             }
//             if(secondSmallest!=INT_MAX){
//                 max_score = max(max_score, smallest + secondSmallest);
//             }
//         }
//     }
//     return max_score;
// }

//!OPTIMAL APPROACH
int pairWithMaxSum(vector<int>& arr){
    int n=arr.size();
    int maxi=0;

    for(int i=0;i<n-1;i++){
        maxi=max(maxi,arr[i]+arr[i+1]);
    }

    return maxi;
}

int main()
{

    vector<int> arr1 = {4, 3, 5, 1, 6};
    vector<int> arr3= {5, 1, 4, 6, 3};
    vector<int> arr2 = {1, 3, 4, 5, 6};

    int ans1 = pairWithMaxSum(arr1);
    int ans2 = pairWithMaxSum(arr2);
    int ans3= pairWithMaxSum(arr3);

    cout << "Answer from Code is: " << ans1 << " whereas Answer orginally is 8" << endl;
    cout << "Answer from Code is: " << ans3 << " whereas Answer orginally is 10" << endl;
    cout << "Answer from Code is: " << ans2 << " whereas Answer orginally is 11" << endl;

    return 0;
}