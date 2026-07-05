#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> &safeNodes, vector<vector<int>> &graph)
    {
        safeNodes[node] = 2;

        for (auto it : graph[node])
        {
            if (safeNodes[it] == 0)
            {
                dfs(it, safeNodes, graph);
            }
            if (safeNodes[it] == 2)
            {
                return;
            }
        }
        safeNodes[node] = 1;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int m = graph[0].size();
        vector<int> safeNodes(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (graph[i].empty())
            {
                safeNodes[i] = 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (safeNodes[i] == 0)
            {
                dfs(i, safeNodes, graph);
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (safeNodes[i] == 1)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }

    vector<vector<int>> listBuilder()
    {   
        int n, m;
        cout<<"Enter No. of Nodes and edges: ";
        cin>>n>>m;

        vector<vector<int>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cout<<"Enter directed Connection: ";
            cin >> u >> v;
            graph[u].push_back(v);
        }
        return graph;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> graph = sol.listBuilder();
    vector<int> ans = sol.eventualSafeNodes(graph);

    cout<<"Safe Nodes are: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}