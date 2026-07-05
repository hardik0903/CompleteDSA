#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    //! BFS
    bool detect(int src, vector<vector<int>> &adj, int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }
        return false;
    }


public:
    //! BFS
    bool isCycle(int V, vector<vector<int>> &adj)
    {
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis) == true)
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