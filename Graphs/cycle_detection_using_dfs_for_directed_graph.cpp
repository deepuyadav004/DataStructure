
#include<bits/stdc++.h>
using namespace std;

// cycle detection in directed grapgh using dfs

bool checkCycle(int node, vector<int> arr[], int vis[], int dfsVis[]){
    vis[node]=1;
    dfsVis[node]=1;
    for(auto it:arr[node]){
        if(!vis[it]){
            if(checkCycle(it, arr, vis, dfsVis)) return true;
        }else if(dfsVis[it]){
            return true;
        }
    }    
    dfsVis[node]=0;
    return false;
}

bool isCycle(int n, vector<int> arr[]){
    int vis[n], dfsVis[n];
    memset(vis, 0, sizeof(vis));
    memset(dfsVis, 0, sizeof(dfsVis));

    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(checkCycle(i, arr, vis, dfsVis)){
                return true;
            }
        }
    }
    return false;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int>arr[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
    }

    for(int i=0; i<=n; i++){
        cout<<i<<" :- ";
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // cycle detection in undirected graph using dfs recursive
    if(isCycle(n, arr)) cout<<"cycle exists proved using dfs"<<endl;
    else cout<<"cycle doesn't exists proved using dfs"<<endl;

    return 0;
}










