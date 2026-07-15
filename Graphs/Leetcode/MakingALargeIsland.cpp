#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size, rank;

    DisjointSet(int n){
        parent.resize(n+1, 1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
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

    void unionByRank(int u, int v){
        int ulParentu = findUParent(u);
        int ulParentv = findUParent(v);

        if(ulParentu == ulParentv){
            return;
        }

        if(rank[ulParentu] > rank[ulParentv]){
            parent[ulParentv] = ulParentu;
        }
        else if(rank[ulParentv] > rank[ulParentu]){
            parent[ulParentu] = ulParentv;
        }
        else{
            parent[ulParentv] = ulParentu;
            rank[ulParentu]++;
        }
    }

    void unionBySize(int u, int v){
        int ulParentu = findUParent(u);
        int ulParentv = findUParent(v);

        if(ulParentu == ulParentv){
            return;
        }

        if(size[ulParentu] > size[ulParentv]){
            parent[ulParentv] = ulParentu;
            size[ulParentu] += size[ulParentv];
        }
        else{
            parent[ulParentu] = ulParentv;
            size[ulParentv] += size[ulParentu];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        DisjointSet ds(grid.size()*grid[0].size()+1);
        for(int i=0;i<grid.size();i++){ 
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0) continue;
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                for(int k=0;k<4;k++){
                    int newR = i+dr[k];
                    int newC = j+dc[k];

                    if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[i].size() && grid[newR][newC]==1){
                        int index = i*grid[i].size()+j;
                        int adjIndex = newR *grid[i].size()+newC;   
                        ds.unionBySize(index, adjIndex);
                    }
                }
            }
        }

        int maxArea=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    unordered_set<int> st;

                    int dr[] = {-1, 1, 0, 0};
                    int dc[] = {0, 0, -1, 1};

                    for(int k=0;k<4;k++){
                        int newR = i+dr[k];
                        int newC = j+dc[k];

                        if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[i].size() && grid[newR][newC]==1){
                            int val = ds.findUParent(newR*grid[i].size() + newC);
                            st.insert(val);
                        }
                    }

                    int currentArea=1;
                    for(auto parent:st){
                        int adjSize = ds.size[parent];
                        currentArea+=adjSize;
                    }
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxArea = max(maxArea, ds.size[ds.findUParent(i*grid[i].size()+j)]);
            }
        }
        return maxArea;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    
    Solution sol;
    int ans = sol.largestIsland(grid);
    cout << ans << "\n";
    
    return 0;
}