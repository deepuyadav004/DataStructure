#include<bits/stdc++.h>
using namespace std;

// dijkistra's algorithm
void dij(vector<pair<int,int>>arr[], int n){
    vector<int>dist(n+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    dist[0]=0;
    pq.push({1, 0});
    while(!pq.empty()){
        int node=pq.top().first;
        int dis=pq.top().second;
        pq.pop();

        for(auto it:arr[node]){
            if(dist[it.first] > dis+it.second){
                dist[it.first]=dis+it.second;
                pq.push({it.first, dist[it.first]});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>arr[n+1];
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr[u].push_back(make_pair(v, wt));
    }

    dij(arr, n);

    return 0;
}
