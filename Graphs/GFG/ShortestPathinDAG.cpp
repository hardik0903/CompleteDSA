#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void topoSort(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st){
        vis[node]=1;

        for(auto it: adj[node]){
            int v=it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }

        st.push(node);
    }
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges, int src){
        vector<vector<pair<int, int>>> adj(V);

        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dist(V, 0);
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        dist[src]=0;

        while(!st.empty()){
            int node=st.top();
            st.pop();

            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dist[node]!=INT_MAX && dist[node]+wt<dist[v]){
                    dist[v]=wt+dist[node];
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

    vector<vector<int>> edgeBuilder(int& i, int& j){
        int n, m;
        cout<<"Enter no. of nodes and edges: ";
        cin>>n>>m;
        vector<vector<int>> edges;
        i=n;
        j=m;

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
    int V, E;
    int src;
    cout<<"Enter source node: ";
    cin>>src;
    vector<vector<int>> edges = sol.edgeBuilder(V, E);
    vector<int> ans = sol.shortestPath(V, E, edges, src);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}