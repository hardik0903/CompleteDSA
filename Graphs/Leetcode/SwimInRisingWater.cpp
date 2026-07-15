#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.assign(n+1, 0);
        size.assign(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulParentu = findUParent(u);
        int ulParentv = findUParent(v);

        if(ulParentu == ulParentv) return;
        if(size[ulParentu] > size[ulParentv]){
            parent[ulParentv] = ulParentu;
            size[ulParentu]+=size[ulParentv];
        }
        else{
            parent[ulParentu]=ulParentv;
            size[ulParentv]+=size[ulParentu];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<tuple<int, int, int>> save;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                save.push_back({grid[i][j], i, j});
            }
        }
        sort(save.begin(), save.end());
        DisjointSet ds(n*m);
        int dr[]={-1, 1, 0, 0};
        int dc[]={0, 0, -1, 1};
        for(auto& t : save){
            int x = get<0>(t);
            int y = get<1>(t);
            int z = get<2>(t);
            
            visited[y][z]=1;
            for(int k=0;k<4;k++){
                int newR = y+dr[k];
                int newC = z+dc[k];

                if(newR>=0 && newR<n && newC>=0 && newC<m && visited[newR][newC]){
                    ds.unionBySize(y*m+z, newR*m+newC);
                }
            }
            if(ds.findUParent(0) == ds.findUParent(n*m-1)) return x;
        }
        return -1;
    }
};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    Solution sol;
    int ans = sol.swimInWater(grid);
    cout << ans << "\n";
    return 0;
}