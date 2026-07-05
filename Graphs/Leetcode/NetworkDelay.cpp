#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDleayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<int> dist(n + 1, 1e9);
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edjW = it.second;

                if (edjW + distance < dist[adjNode])
                {
                    dist[adjNode] = edjW + distance;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i < dist.size(); i++)
        {
            if (dist[i] == 1e9)
            {
                return -1;
            }
            if (ans < dist[i])
            {
                ans = dist[i];
            }
        }
        return ans;
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
int main()
{

    Solution sol;
    int V;
    vector<vector<int>> times;
    cout << "Enter Number of Nodes: ";
    cin >> V;

    sol.listBuilder(times, V);
    int k;
    cout<<"Enter Source Node: ";
    cin>>k;
    int ans=sol.networkDleayTime(times, V, k);
    cout<<"Answer is: "<<ans;
    return 0;
}