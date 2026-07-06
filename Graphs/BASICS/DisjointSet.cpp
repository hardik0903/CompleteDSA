#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, rank, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){

        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){

        int ulParentu = findUParent(u);
        int ulParentv = findUParent(v);

        if(ulParentu == ulParentv){
            return;
        }

        if(rank[ulParentu] > rank[ulParentv]){
            parent[ulParentv] = ulParentu;
        }
        else if(rank[ulParentv] > rank[ulParentu]){
            parent[ulParentu] = ulParentv;
        }
        else{
            parent[ulParentv] = ulParentu;
            rank[ulParentu]++;
        }
    }

    void unionBySize(int u, int v){
        int ulParentu = findUParent(u);
        int ulParentv = findUParent(v);

        if(ulParentu==ulParentv) return;

        if(size[ulParentu] > size[ulParentv]){
            parent[ulParentv] = ulParentu;
            size[ulParentu]+=size[ulParentv];
        }
        else{
            parent[ulParentu] = ulParentv;
            size[ulParentv]+=size[ulParentu];
        }
    }
};

int main(){

    int V;
    cout<<"Enter number of Vertices: ";
    cin>>V;

    int E;
    cout<<"Enter Numer of Edges: ";
    cin>>E;
    DisjointSet ds(V);
    for(int i=0;i<E;i++){
        int u, w;
        cout<<"Enter the edge: ";
        cin>>u>>w;
        ds.unionByRank(u, w);
    }

    int node1, node2;
    cout<<"Enter the nodes between which similarity needs to be searched: ";
    cin>>node1>>node2;
    if(ds.findUParent(node1) == ds.findUParent(node2)){
        cout<<"Same Parent"<<endl;
    }
    else{
        cout<<"Not Same Parent"<<endl;
    }
}