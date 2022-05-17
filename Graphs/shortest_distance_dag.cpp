
#include<bits/stdc++.h>
using namespace std;

// returns topological sort
void topo(int node, vector<pair<int,int>>arr[], stack<int>&st, vector<int> &vis){
    vis[node]=1;
    for(auto it:arr[node]){
        if(!vis[it.first]){
            topo(it.first, arr, st, vis);
        }
    }
    st.push(node);
}

void shortest_distance(vector<pair<int,int>>arr[], int n){
    vector<int>dis(n, INT_MAX);
    stack<int>st;
    vector<int>vis(n,0);
    topo(0, arr, st, vis);
    dis[0]=0;

    while(!st.empty()){
        int node=st.top();
        st.pop();

        if(dis[node] != 1e9){
            for(auto it:arr[node]){
                if(dis[node]+it.second < dis[it.first]){
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(dis[i] != 1e9){
            cout<<"Distance b/w "<<0<<" and "<<i<<" = "<<dis[i]<<endl;
        }else{
            cout<<"distance b/w "<<0<<" and "<<i<<" = INF"<<endl;
        }
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr[n+1];
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr[u].push_back({v,wt});
    }

    // shortest distance between node in directed graph
    shortest_distance(arr, n);


    return 0;
}
