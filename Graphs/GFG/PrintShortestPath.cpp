#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq;
        vector<int> dist(n+1);
        vector<int> parent(n+1);

        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        for(int i=1;i<=n;i++){
            dist[i]=1e9;
            parent[i]=i;
        }

        pq.push({0, 1});
        dist[1]=0;
        parent[1]=1;

        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                int nodeWeight = it.second;
                int adjNode = it.first;

                if(nodeWeight+dis < dist[adjNode]){
                    dist[adjNode] = dis+nodeWeight;
                    parent[adjNode]=node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if(dist[n]==1e9){
            return {-1};
        }

        int node = n;
        vector<int> path;

        while(parent[node]!=node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        vector<int> result;
        result.push_back(dist[n]);
        for(int n:path){
            result.push_back(n);
        }
        return result;
    }
    vector<int> edgeBuilder(int& i, int& j){
        int n, m;
        vector<vector<int>> edges;
        cout<<"Enter Number of Nodes and Edges: ";
        cin>>n>>m;
        i=n;
        j=m;

        for(int k=0;k<m;k++){
            int n1, n2, w;
            cout<<"Enter Connection: ";
            cin>>n1>>n2>>w;
            vector<int> edge = {n1, n2, w};
            edges.push_back(edge);
        }
        return edges;
    }
};

int main(){
    Solution sol;
    int i, j;
    vector<vector<int>> edges = sol.edgeBuilder(i,j);
    vector<int> ans =sol.shortestPath(i, j, edges);

    for(int i:ans){
        cout<<i<<" ";
    }
}
