#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int cheapestFlights(int n, vector<vector<int>>& flights, int src, int dst, int k){

        vector<vector<int>> adj[n+1];

        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dist[src]=0;

        while(!q.empty()){
            auto it=q.front();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            q.pop();

            if(stops>k) continue;

            for(auto iter:adj[node]){
                int adjNode = iter[0];
                int edjW = iter[1];

                if(cost+edjW < dist[adjNode] && stops<=k){
                    dist[adjNode] = cost+edjW;
                    q.push({stops+1, {adjNode, dist[adjNode]}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

int main(){

    int src, n, dst;

    cout<<"Enter Number of Nodes, Source Node and Destination Node: ";
    cin>>n>>src>>dst;
    int edge;
    cout<<"Enter Number of Edges: ";
    cin>>edge;
    int k;
    cout<<"Enter Number of Stops: ";
    cin>>k;
    vector<vector<int>> inp(edge);
    for(int i=0;i<edge;i++){
        int fromNode, toNode, cost;
        cout<<"Enter Connection: ";
        cin>>fromNode>>toNode>>cost;
        inp[i] = {fromNode, toNode, cost};
    }

    Solution sol;
    int ans = sol.cheapestFlights(n, inp, src, dst, k);
    cout<<"Answer is: "<<ans;
}