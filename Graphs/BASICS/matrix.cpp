#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;

    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            if(adj[i][j]==1){
                cout<<adj[i][j]<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}