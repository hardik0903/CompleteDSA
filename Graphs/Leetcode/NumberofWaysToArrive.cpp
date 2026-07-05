#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> builder(int &n)
    {
        vector<vector<int>> roads;

        int m = n;

        while (m > 0)
        {
            vector<int> road;
            int i = 3;
            int sourceNode, targetNode, costOverall;
            cout << "Enter Source Node, Target Node, Cost Overall: ";
            cin >> sourceNode >> targetNode >> costOverall;
            road.push_back(sourceNode);
            road.push_back(targetNode);
            road.push_back(costOverall);
            roads.push_back(road);
            m--;
        }
        return roads;
    }

    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);

        while (!pq.empty())
        {
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                long long edjW = it.second;

                if (edjW + dis < dist[adjNode])
                {
                    pq.push({dis + edjW, adjNode});
                    dist[adjNode] = dis + edjW;
                    ways[adjNode] = ways[node];
                }
                else if (edjW + dis == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

int main()
{
    int n, e;
    cout << "Enter length of roads: ";
    cin >> n;
    cout<< "Enter Number of Edges: ";
    cin>>e;

    Solution sol;
    vector<vector<int>> roads = sol.builder(e);
    int ans = sol.countPaths(n, roads);
    cout << "Our Answer is: " << ans;
}