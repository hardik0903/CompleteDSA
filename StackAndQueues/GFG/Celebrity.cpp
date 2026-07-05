#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    //! NAIVE APPROACH
    // int celebrity(vector<vector<int> >& mat) {
    //     // code here
    //     int n=mat.size();
    //     vector<int> knownby(n,0);
    //     vector<int> knows(n,0);
        
        
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(i==j) continue;
    //             if(mat[i][j]==1){
    //                 knownby[j]++;
    //                 knows[i]++;
    //             }
    //         }
    //     }
        
    //     for(int i=0;i<n;i++){
    //         if(knownby[i]==n-1 && knows[i]==0){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    //! OPTIMAL APPROACH
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int top=0;
        int down=n-1;
        
        while(top<down){
            if(mat[top][down]==1){
                top++;
            }
            // else if(mat[down][top]==1){
            //     down--;
            // }
            else{
                // top++;
                down--;
            }
        }
        if(top>down) return -1;
        
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if(mat[top][i]==1 || mat[i][top]==0) return -1;
        }
        return top;
    }
};

int main() {
    Solution sol;
    
    // Hard‑coded example:
    // 0,1,1,0
    // 0,0,0,0
    // 0,1,0,0
    // 1,1,0,0
    vector<vector<int>> mat = {
        {0,1,1,0},
        {0,1,0,0},
        {0,1,0,0},
        {1,1,0,0}
    };
    
    int ans = sol.celebrity(mat);
    cout << "Celebrity index: " << ans << "\n";  // Expected output: 1
    return 0;
}
