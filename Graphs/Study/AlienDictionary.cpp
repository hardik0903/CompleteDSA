#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findOrder(int V, vector<string>& words){
        vector<vector<int>> adj(V);

        for(int i=0;i<words.size()-1;i++){
            string first = words[i];
            string second = words[i+1];

            for(int j=0;j<(min(first.size(), second.size()));j++){
                if(first[j]!=second[j]){
                    adj[first[j]-'a'].push_back(second[j]-'a');
                    break;
                }
            }
        }

        vector<int> indegree(V);

        for(int i=0;i<V;i++){
            for(int it:adj[i]){
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
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(int it:adj[node]){
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
    Solution sol;
    int V=6;
    vector<string> words = {"ab", "cd", "ef", "ad"};
    vector<int> ans = sol.findOrder(V, words);

    for(int i:ans){
        cout<<i<<" ";
    }
}