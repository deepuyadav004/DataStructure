
#include<bits/stdc++.h>
using namespace std;

int parent[10000];
int ranks[10000];

void makeSet(){
    for(int i=1; i<10000; i++){
        parent[i]=i;
        ranks[i]=0;
    }
}

int findPar(int node){
    if(node == parent[node]){
        return node;
    }

    return parent[node] = findPar(parent[node]);
}

void unionfind(int u, int v){
    u=findPar(u);
    v=findPar(v);

    if(ranks[u] < ranks[v]){
        parent[u]=v;
    }else if(ranks[u] > ranks[v]){
        parent[v]=u;
    }else{
        parent[u]=v;
        ranks[v]++;
    }
}

int main(){
    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        unionfind(u,v);
    }

    if(findPar(3) != findPar(6)){
        cout<<"Different parents"<<endl;
    }else{
        cout<<"Same parents"<<endl;
    }
    return 0;
}


