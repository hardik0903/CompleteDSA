#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

//!BRUTE-FORCE APPROACH
int median(vector<vector<int>> &matrix, int m, int n){

    vector<int> ls;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ls.push_back(matrix[i][j]);
        }
    }

    sort(ls.begin(),ls.end());
    return (ls[(n*m)/2]);
}

//!OPTIMAL CODE USING INARY SEARCH
// int upperbound(vector<int>& mat, int target){
//     int low=0;
//     int high=mat.size()-1;
//     int ans=mat.size();
//     while(low<=high){
//         int mid=(low+high)/2;

//         if(mat[mid]>target){
//             ans=mid;
//             high=mid-1;
//         }
//         else{
//             low=mid+1;
//         }
//     }
//     return ans;
// }

// int CountSmallerEquals(vector<vector<int>>& arr, int n, int m, int mid){
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         cnt+=upperbound(arr[i],mid);
//     }
//     return cnt;
// }

// int median(vector<vector<int>> &matrix, int m, int n) {

//     int low=INT_MAX;
//     int high=INT_MIN;
//     int required=(n*m)/2;

//     for (int i = 0; i < m; i++) {
//         low = min(low, matrix[i][0]);
//         high = max(high, matrix[i][n - 1]);
//     }

//     while(low<=high){
//         int mid=(low+high)/2;
//         int smallerOnes=CountSmallerEquals(matrix, m, n, mid);
//         if(smallerOnes<=required){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return low;
// }

int main(){
    vector<vector<int>> matrix = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    };

    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
return 0;
}