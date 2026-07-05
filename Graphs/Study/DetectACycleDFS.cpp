#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    //! DFS
    bool dfs(int node, int parent, int vis[], vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, node, vis, adj) == true)
                {
                    return true;
                }
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
        return false;
    }
    
public:
    //! DFS
    bool isCycle(int V, vector<vector<int>> &adj)
    {
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
    

    vector<vector<int>> listContructor()
    {
        cout << "Enter Number of nodes and edges: " << endl;
        int n, m;

        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        cout << "Start Entering connected nodes: " << endl;

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
    Solution sol;
    vector<vector<int>> ans = sol.listContructor();
    int V = ans.size();
    bool cal = sol.isCycle(V, ans);
    if (cal)
    {
        cout << "Cycle was founded" << endl;
    }
    else
    {
        cout << "Cycle wasn't there" << endl;
    }
}