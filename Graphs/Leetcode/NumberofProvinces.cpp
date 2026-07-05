#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int start, vector<vector<int>>& adjLs, vector<int>& vis)
    {
        vis[start] = 1;
        for (auto it : adjLs[start])
        {
            if (!vis[it])
            {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int numberofProvinces(vector<vector<int>>& adj)
    {
        int V = adj.size();
        vector<vector<int>> adjLs(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }

    vector<vector<int>> matrixContructor()
    {
        cout<<"Enter Number of nodes and edges: "<<endl;
        int n, m;

        cin >> n >> m;
        vector<vector<int>> adj(n, vector<int>(n, 0));
        cout<<"Start Entering connected nodes: "<<endl;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u-1][v-1] = 1;
            adj[v-1][u-1] = 1;
        }

        return adj;
    }
};

int main(){
    Solution sol;
    cout<<"Start Forming the matrix:"<<endl;
    vector<vector<int>> ans = sol.matrixContructor();
    int cnt = sol.numberofProvinces(ans);
    cout<<"Number of Provinces: "<<cnt;
}