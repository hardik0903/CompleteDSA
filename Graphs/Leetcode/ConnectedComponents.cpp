#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size, rank;
    
    DisjointSet(int n){
        parent.resize(n+1, 0); 
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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;
        
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUParent(u) == ds.findUParent(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }

        int cntC = 0;
        // Nodes are 0-indexed in this problem (0 to n-1)
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                cntC++;
            }
        }

        if(extraEdges >= (cntC - 1)){
            return (cntC - 1);
        }
        return -1;
    }
};

int main(){
    int n, E;
    cout << "Enter number of computers (n) and number of connections (E): ";
    cin >> n >> E;

    Solution sol;
    vector<vector<int>> connections;
    
    for(int i = 0; i < E; i++){
        int u, v;
        cout << "Enter connection " << i + 1 << " (u v): ";
        cin >> u >> v;
        connections.push_back({u, v});
    }

    int minOperations = sol.makeConnected(n, connections);
    
    if(minOperations == -1) {
        cout << "\nResult: -1 (Not enough extra cables to connect all computers).\n";
    } else {
        cout << "\nResult: Minimum operations to connect all computers: " << minOperations << "\n";
    }

    return 0;
}