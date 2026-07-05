#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();

        vector<int> dr= {-1, 0, +1, 0};
        vector<int> dc= {0, +1, 0, -1};

        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='0' && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
public:
    vector<vector<char>> surroundedRegions(vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int j=0;j<m;j++){
            if(grid[0][j]=='0'){
                dfs(0, j, grid, vis);
            }
            if(grid[n-1][j]=='0'){
                dfs(n-1, j, grid, vis);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][0]=='0'){
                dfs(i, 0, grid, vis);
            }
            if(grid[i][m-1]=='0'){
                dfs(i, m-1, grid, vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0' && !vis[i][j]){
                    grid[i][j]='X';
                }
            }
        }
        return grid;
    }
    vector<vector<char>> matrixBuilder(){

        int row, col;

        cout<<"Enter size of the matrix(row and col): ";
        cin>>row>>col;
        vector<vector<char>> mat(row, vector<char>(col, 'X'));

        int count;
        cout<<"Enter Number of 0's you need in the matrix: ";
        cin>>count;

        if(count>(row+col)){
            cout<<"Invalid number of 0's";
            return {};
        }

        for(int i=0;i<count;i++){
            
            int indexRow, indexCol;

            cout<<"Enter Index(Row and Col) for 0's: ";
            cin>>indexRow>>indexCol;


            mat[indexRow][indexCol]='0';

        }
        return mat;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = sol.matrixBuilder();
    vector<vector<char>> ans = sol.surroundedRegions(grid);

    int n=ans.size();
    int m=ans[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}