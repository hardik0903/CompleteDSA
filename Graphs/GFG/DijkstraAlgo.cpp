#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    //!USING PRIORITY QUEUE
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        
        dist[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

    //!USING SET
    // vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    //     // Code here
    //     vector<vector<pair<int, int>>> adj(V);
        
    //     for(int i=0;i<edges.size();i++){
    //         int u = edges[i][0];
    //         int v = edges[i][1];
    //         int w = edges[i][2];
            
    //         adj[u].push_back({v, w});
    //         adj[v].push_back({u, w});
    //     }
        
    //     // for(int i=0;i<adj.size();i++){
    //     //     for(int j=0;j<adj[0].size()-1;j++){
    //     //         cout<<adj[i]<<"->"<<" "<<adj[j]<<adj[j+1];
    //     //     }
    //     //     cout<<endl;
    //     // }
        
    //     set<pair<int, int>> st;
    //     vector<int> dist(V, 1e9);
        
    //     st.insert({0, src});
    //     dist[src]=0;
        
    //     while(!st.empty()){
    //         auto it = *(st.begin());
    //         int dis = it.first;
    //         int node = it.second;
    //         st.erase(it);
            
    //         for(auto it:adj[node]){
    //             int edgeW=it.second;
    //             int adjN = it.first;
                
    //             if(dist[adjN] > dis+edgeW){
    //                 if(dist[adjN]!=1e9){
    //                     st.erase({dist[adjN], adjN});
    //                 }
    //                 dist[adjN]=dis+edgeW;
    //                 st.insert({dist[adjN], adjN});
    //             }
    //         }
    //     }
    //     return dist;
    // }

    vector<vector<int>> edgeBuilder(int& i){
        int n, m;
        cout<<"Enter no. of nodes and edges: ";
        cin>>n>>m;
        vector<vector<int>> edges;
        i=n;

        for(int i=0;i<m;i++){
            int u, v, w;
            cout<<"Enter connection: ";
            cin>>u>>v>>w;
            vector<int> edge = {u, v, w};
            edges.push_back(edge);
        }
        return edges;
    }
};

int main(){
    Solution sol;
    int src=0;
    int V=0;
    vector<vector<int>> edge = sol.edgeBuilder(V);
    vector<int> ans = sol.dijkstra(V, edge, src);

    for(int it: ans){
        cout<<it<<" ";
    }

}