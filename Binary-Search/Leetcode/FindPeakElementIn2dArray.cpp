#include <iostream>
#include <climits>
#include <vector>

using namespace std;

// vector<int> findPeakElement(vector<vector<int>>& mat){
//     int n=mat.size();
//     int m=mat[0].size();

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             int left=j-1>=0 ? mat[i][j-1]:-1;
//             int right=j+1<m ? mat[i][j+1]:-1;
//             int top=i-1>=0 ? mat[i-1][j]:-1;
//             int down=i+1<n ? mat[i+1][j]:-1;

//             if(mat[i][j]>left && mat[i][j]>right && mat[i][j]>top && mat[i][j]>down){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }

int RowNumber(vector<vector<int>>& mat, int n, int m, int mid){
    int maxi=-1;
    int index=-1;

    for(int i=0;i<n;i++){
        if(maxi<mat[i][mid]){
            maxi=mat[i][mid];
            index=i;
        }
    }
    return index;
}

vector<int> findPeakElement(vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();

    int low=0;
    int high=m-1;

    while(low<=high){
        int mid=(low+high)/2;
        int row=RowNumber(mat,n,m,mid);
        int left=mid-1>=0 ? mat[row][mid-1]:-1;
        int right=mid+1<m ? mat[row][mid+1]:-1;

        if(mat[row][mid]>left && mat[row][mid]>right){
            return {row,mid};
        }
        else if(mat[row][mid]<left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> arr={
        {4,2,5,1,4,5},
        {2,9,3,2,3,2},
        {1,7,6,0,1,3},
        {3,6,2,3,7,2}
    };

    vector<int> ans=findPeakElement(arr);
    int n=ans.size();

    cout<<"Calculated Anwer is: ";
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<" Whereas Real Answer is: (0,0) or (0,2) or (0,5) or (1,1) or (2,5) or (3,4)";
return 0;
}