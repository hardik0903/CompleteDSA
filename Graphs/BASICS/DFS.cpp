#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    void dfs(int node, vector<vector<int>>& adj, int vis[], vector<int>& ls){
        vis[node]=1;
        ls.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> dfsofGraph(vector<vector<int>> &adj)
    {
        int V = adj.size();
        int vis[V]={0};
        int start=1;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }

    vector<vector<int>> adjacentListMaker()
    {
        int n, m;
        cout << "Enter number of nodes and edges: " << endl;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);
        cout << "Start Entering the connected nodes numbers: " << endl;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
};

int main()
{
    Graph gp;
    cout << "Start creating the graph:" << endl;
    vector<vector<int>> ans = gp.adjacentListMaker();
    vector<int> traversed = gp.dfsofGraph(ans);

    for (auto it : traversed)
    {
        cout << it << " ";
    }
    return 0;
}