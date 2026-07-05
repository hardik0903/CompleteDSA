#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void floydWarshall(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int k = 0; k < n; k++)
        {

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (matrix[i][k]==-1 || matrix[k][j]==-1)
                        continue;

                    if (matrix[i][j] == -1)
                        matrix[i][j] = matrix[i][k] + matrix[k][j];

                    else
                    {
                        matrix[i][j] = min(matrix[i][k] + matrix[k][j], matrix[i][j]);
                    }
                }
            }
        }
    }

    vector<vector<int>> matrixBuilder(vector<vector<pair<int, int>>> &adjList)
    {
        vector<vector<int>> matrix;
        int n = adjList.size();
        matrix.assign(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            matrix[i][i] = 0;
        }

        for (int u = 0; u < n; u++)
        {
            for (auto edge : adjList[u])
            {
                matrix[u][edge.first] = edge.second;
            }
        }
        return matrix;
    }

    void listBuilder(vector<vector<pair<int, int>>> &adj)
    {
        int m;
        cout<<"Enter Number of edges: ";
        cin>>m;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cout<<"Enter initial, final edges and weight of the edge: ";
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }
    }
};

int main()
{
    int V;
    cout<<"Enter Numbers of Vertices: ";
    cin>>V;

    vector<vector<pair<int, int>>> adj(V);

    Solution sol;
    sol.listBuilder(adj);

    vector<vector<int>> matrix = sol.matrixBuilder(adj);
    sol.floydWarshall(matrix);

    for(int i=0;i<matrix[0].size();i++){
        for(int j=0;j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}