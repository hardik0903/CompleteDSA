#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
  void dfs(int node, vector<int>& vis, vector<vector<int>>& edges, stack<int>& st){
      vis[node]=1;
      
      for(auto it:edges[node]){
          if(vis[it]==1) continue;
          else{
              dfs(it, vis, edges, st);
          }
      }
      st.push(node);

  }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
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

