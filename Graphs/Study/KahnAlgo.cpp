#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        queue<int> q;
        vector<int> indegree(V);
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo;
        
    }
    vector<vector<int>> edgeBuilder(int& i){
        int n, m;
        cout<<"Enter no. of nodes and edges: ";
        cin>>n>>m;
        vector<vector<int>> edges;
        i=n;

        for(int i=0;i<m;i++){
            int u, v;
            cout<<"Enter connection: ";
            cin>>u>>v;
            vector<int> edge = {u, v};
            edges.push_back(edge);
        }
        return edges;
    }
};
    

int main(){
    Solution sol;
    int V;
    vector<vector<int>> edges = sol.edgeBuilder(V);
    vector<int> ans = sol.topoSort(V, edges);

    for(auto it:ans){
        cout<<it<<" ";
    }
}

