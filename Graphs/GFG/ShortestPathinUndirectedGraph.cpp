#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        dist[src]=0;
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(dist[it]>distance+1){
                    q.push({it, distance+1});
                    dist[it]=distance+1;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        
        return dist;
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
    int V=0;
    vector<vector<int>> edges = sol.edgeBuilder(V);
    int src;
    cout<<"Enter source node: ";
    cin>>src;

    vector<int> ans = sol.shortestPath(V, edges, src);
    for(auto i:ans){
        cout<<i<<" ";
    }
}

