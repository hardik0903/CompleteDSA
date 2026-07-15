#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 1);
        size.resize(n+1, 1);
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

        if(ulParentu==ulParentv) return;

        if(size[ulParentu] > size[ulParentv]){
            parent[ulParentv] = ulParentu;
            size[ulParentu]+=size[ulParentv];
        }
        else{
            parent[ulParentu] = ulParentv;
            size[ulParentv]+=size[ulParentu];
        }
    }
};

class Solution{
public:

    int mostStonesRemoved(vector<vector<int>>& stones){
        int n=stones.size();
        int maxRows = 0;
        int maxCols = 0;

        for(auto it:stones){
            maxRows = max(maxRows, it[0]);
            maxCols = max(maxCols, it[1]);
        }

        unordered_map<int, int> mp;
        DisjointSet ds(maxRows+maxCols+1);

        for(auto it:stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRows + 1;
            ds.unionBySize(nodeRow, nodeCol);
            mp[nodeRow]=1;
            mp[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findUParent(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};

int main(){
    vector<vector<int>> stones;

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int first, second;
        cin>>first>>second;
        stones.push_back({first, second});
    }
    Solution sol;
    int ans = sol.mostStonesRemoved(stones);
    cout<<ans;
}