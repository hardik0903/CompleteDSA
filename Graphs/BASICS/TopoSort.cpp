#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> topoSortDFS(vector<vector<int>> &adj, int V)
    {
        vector<int> vis(V);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    void listBuilder(int &n, vector<vector<int>>& adj)
    {
        
        int m;
        cout<<"Enter Number of Edges: ";
        cin>>m;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
    }

    vector<int> topoSortBFS(vector<vector<int>>& adj, int V){
        vector<int> indegree(V);

        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

int main(){

    int V;
    
    cout<<"Enter Number of Vertices: ";
    cin>>V;
    vector<vector<int>> adj(V);

    Solution sol;
    sol.listBuilder(V, adj);

    // vector<int> ans = sol.topoSortDFS(adj, V);
    vector<int> ans2=sol.topoSortBFS(adj, V);

    // for(int i=0;i<ans.size();i++){
    //     cout<<" "<<ans[i]<<" ";
    // }

    for(int i=0;i<ans2.size();i++){
        cout<<" "<<ans2[i]<<" ";
    }

    return 0;

}
