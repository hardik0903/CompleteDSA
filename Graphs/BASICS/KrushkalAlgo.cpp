#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size, rank;

public:
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

        if(ulParentu == ulParentv) return;

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
    int krushkalAlgo(vector<vector<int>>& edges, int V){
        vector<pair<int, pair<int, int>>> adj;

        for(auto it:edges){
            adj.push_back({it[0], {it[1], it[2]}});
        }
        DisjointSet ds(V);
        sort(adj.begin(), adj.end());
        int mstW=0;
        for(auto it:adj){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUParent(u)!=ds.findUParent(v)){
                mstW+=wt;
                ds.unionByRank(u, v);
            }
        }
        return mstW;
    }
};

int main(){
    int V, E;
    cout<<"Enter number of Vertices and Edges: ";
    cin>>V>>E;

    Solution sol;
    vector<vector<int>> edges;
    for(int i=0;i<E;i++){
        int wt, u, v;
        cout<<"Enter weight and connection of edges: ";
        cin>>wt>>u>>v;
        edges.push_back({wt, u, v});
    }

    int totalWeight = sol.krushkalAlgo(edges, V);
    cout<<"Final MST weight: "<<totalWeight;
}