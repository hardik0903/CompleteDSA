#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
    vector<int> dijkstra1(vector<vector<pair<int, int>>>& adj, int V, int src){

        vector<int> dist(V, 1e9);
        dist[src]=0;
        set<pair<int, int>> st;
        st.insert({0, src});

        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int distance = it.first;
            st.erase(st.begin());

            for(auto itt:adj[node]){
                int adjNode = itt.first;
                int edjW = itt.second;

                if(edjW+distance < dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode]=distance+edjW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    void listBuilder(vector<vector<pair<int, int>>>& adj, int& V){
        int m;
        cout<<"Enter number of edges: ";
        cin>>m;

        for(int i=0;i<m;i++){
            int u, v, w;
            cout<<"Enter Connection and Edgeweight: ";
            cin>>u>>v>>w;
            adj[u].push_back({v, w});
        }
    }

    vector<int> dijkstra2(vector<vector<pair<int, int>>>& adj, int V, int src){
        vector<int> dist(V, 1e9);
        priority_queue
        <pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;

        pq.push({0, src});
        dist[src]=0;

        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if(distance>dist[node]) continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edjW = it.second;

                if(edjW+distance < dist[adjNode]){
                    dist[adjNode]=edjW+distance;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main(){
    int V;
    vector<vector<pair<int, int>>> adj(V);
    

    cout<<"Enter number of Vertices: ";
    cin>>V;

    Solution sol;
    sol.listBuilder(adj, V);
    vector<int> ans = sol.dijkstra2(adj, V, 0);

    for(int i=0;i<V;i++){
        cout<<" "<<ans[i];
    }
}