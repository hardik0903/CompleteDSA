#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> bellmanFord(vector<vector<int>>& graph, int V, int S){
        vector<int> dist(V, 1e9);
        dist[S]=0;

        for(int i=0;i<V-1;i++){
            for(auto it:graph){
                int u=it[0];
                int v=it[1];
                int w=it[2];

                if(dist[u]!=1e9 && dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w;
                }
            }

            for(auto it:graph){
                int u=it[0];
                int v=it[1];
                int w=it[2];

                if(dist[u]!=1e9 && dist[u]+w < dist[v]){
                    return {-1};
                }
            }
        }
        return dist;
    }

    void listBuilder(vector<vector<int>> &times, int n)
    {
        int edges;
        cout << "Enter the number of edges: ";
        cin >> edges;

        cout << "Enter each edge in the format: source destination weight\n";
        for (int i = 0; i < edges; i++)
        {
            int u, v, w;
            cout << "Edge " << i + 1 << ": ";
            cin >> u >> v >> w;

            times.push_back({u, v, w});
        }
    }
};
int main() {
    Solution sol;
    int V;
    cout<<"Enter Number of Nodes: ";
    cin>>V;

    vector<vector<int>> edges;
    sol.listBuilder(edges, V);
    int s;
    cout<<"Enter Source Node: ";
    cin>>s;

    vector<int> ans = sol.bellmanFord(edges, V, s);

    for(int i=0;i<ans.size();i++){
        cout<<" "<<ans[i];
    }
return 0;
}