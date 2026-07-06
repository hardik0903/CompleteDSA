#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
    int PrimsAlgo(vector<vector<int>>& edges, int V){
        vector<vector<pair<int, int>>> adj(V+1);
        for(auto& it:edges){
            adj[it[1]].push_back({it[2], it[0]});
            adj[it[2]].push_back({it[1], it[0]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        
        pq.push({0, 1});
        int sum=0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node]=1;
            sum+=weight;
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edjW = it.second;
                
                if(!vis[adjNode]){
                    pq.push({edjW, adjNode});
                }
            }
        }
        return sum;
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

    int totalWeight = sol.PrimsAlgo(edges, V);
    cout<<"Final MST weight: "<<totalWeight;
}