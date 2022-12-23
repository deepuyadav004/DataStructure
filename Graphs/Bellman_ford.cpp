
#include<bits/stdc++.h>
using namespace std;

int main(){

    // taking inputs
    int nodes, edges;
    cin>>nodes>>edges;
    vector<vector<int>>edge;
    for(int i=0; i<edges; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    vector<int>dist(nodes,INT_MAX);
    int source;
    cin>>source;
    dist[source]=0;

    // iterating on all edges n-1 times for relaxation and updataion of distance;
    for(int i=0; i<nodes-1; i++){
        for(auto it : edge){
            int u,v,w;
            u=it[0];
            v=it[1];
            w=it[2];
            if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    }

    // checking for -ve cycle. If distance array got updated in nth cycle means -ve cycle is present
    for(auto it : edge){
        int u,v,w;
        u=it[0];
        v=it[1];
        w=it[2];
        if(dist[u] != INT_MAX && dist[u]+w < dist[v]){
            cout<<"Negative cycle detected"<<endl;
            return 0;
        }
    }

    // if no -ve cycle than printing shortest distance from source to all other nodes;
    puts("Shortest path from source to all other nodes is ");
    for(int i=0; i<nodes; i++){
        cout<<source<<"-->"<<i<<" = "<<dist[i]<<endl;
    }
    return 0;
}
