#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<int> bfsofGraph(vector<vector<int>> &adj)
    {
        int V = adj.size();
        vector<int> vis(V, 0);
        vis[1] = 1;
        queue<int> q;
        vector<int> bfs;
        q.push(1);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
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
    vector<int> traversed = gp.bfsofGraph(ans);

    for (auto it : traversed)
    {
        cout << it << " ";
    }
    return 0;
}