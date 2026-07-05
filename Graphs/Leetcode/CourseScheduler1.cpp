#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);

        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        int cnt=0;
        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return cnt==numCourses;
    }
    vector<vector<int>> edgeBuilder(int& i){
        int n, m;
        cout<<"Enter no. of nodes and edges: ";
        cin>>n>>m;
        vector<vector<int>> edges;
        i=n;

        for(int i=0;i<m;i++){
            int u, v;
            cout<<"Enter connection: ";
            cin>>u>>v;
            vector<int> edge = {u, v};
            edges.push_back(edge);
        }
        return edges;
    }
};

int main(){
    Solution sol;
    int V;
    vector<vector<int>> edges = sol.edgeBuilder(V);
    
    if(sol.canFinish(V, edges)){
        cout<<"Possible"<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
    }
}