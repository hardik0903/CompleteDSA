#include <bits/stdc++.h>
using namespace std;

class Solution{

public:

    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i, j}, 0});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();

            dist[row][col]=step;
            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, step+1});
                    vis[nrow][ncol]=1;
                }
            }
        }

        return dist;
    }

    vector<vector<int>> matrixBuilder(){

        int row, col;

        cout<<"Enter size of the matrix(row and col): ";
        cin>>row>>col;
        vector<vector<int>> mat(row, vector<int>(col, 1));

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


            mat[indexRow][indexCol]=0;

        }
        return mat;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = sol.matrixBuilder();
    vector<vector<int>> ans = sol.nearest(matrix);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}