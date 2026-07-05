#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    // void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
    //     vis[row][col]=1;
    //     int n=grid.size();
    //     int m=grid[0].size();

    //     vector<int> dr={-1, 0, +1, 0};
    //     vector<int> dc={0, +1, 0, -1};

    //     for(int i=0;i<4;i++){
    //         int nrow = row+dr[i];
    //         int ncol = col+dc[i];

    //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
    //             dfs(nrow, ncol, grid, vis);
    //         }
    //     }
    // }
public:
    // int numberofEnclaves(vector<vector<int>>& grid){
    //     int n=grid.size();
    //     int m=grid[0].size();
        
    //     vector<vector<int>> vis(n, vector<int>(m, 0));

    //     for(int j=0;j<m;j++){
    //         if(grid[0][j]==1){
    //             dfs(0, j, grid, vis);
    //         }
    //         if(grid[n-1][j]==1){
    //             dfs(n-1, j, grid, vis);
    //         }
    //     }

    //     for(int i=0;i<n;i++){
    //         if(grid[i][0]==1){
    //             dfs(i, 0, grid, vis);
    //         }
    //         if(grid[i][m-1]==1){
    //             dfs(i, m-1, grid, vis);
    //         }
    //     }
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]==1 && !vis[i][j]){
    //                 cnt++;
    //             }
    //         }
    //     }
    //     return cnt;
    // }

    int numberofEnclaves(vector<vector<int>>& grid){
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dr={-1, 0, +1, 0};
        vector<int> dc={0, +1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i, j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    vector<vector<int>> matrixBuilder(){

        int row, col;

        cout<<"Enter size of the matrix(row and col): ";
        cin>>row>>col;
        vector<vector<int>> mat(row, vector<int>(col, 0));

        int count;
        cout<<"Enter Number of 1's you need in the matrix: ";
        cin>>count;

        if(count>(row+col)){
            cout<<"Invalid number of 1's";
            return {};
        }

        for(int i=0;i<count;i++){
            
            int indexRow, indexCol;

            cout<<"Enter Index(Row and Col) for 1's: ";
            cin>>indexRow>>indexCol;


            mat[indexRow][indexCol]=1;

        }
        return mat;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = sol.matrixBuilder();
    int ans = sol.numberofEnclaves(matrix);

    cout<<ans;
}