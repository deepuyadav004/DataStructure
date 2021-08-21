// Dijkstra algorithm used to find the shortest distance between two edges of graph

#include<bits/stdc++.h>
using namespace std;

// dijkstra function
vector<int> dijkstra(vector<vector<pair<int,int>>> gr, int start){
    vector<int> dist(gr.size(), INT_MAX);

    // <weight, vertex> pair. first element of priority queue will be minimum
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;

    // Add start to p where distance is zero
    p.push(make_pair(0,start));
    dist[start]=0;

    while(!p.empty()){
        
        // Get minimum distance vertex from p
        int u=p.top().second;
        p.pop();

        for(int i=0; i<gr[u].size(); i++){

            int v=gr[u][i].first;
            int weight=gr[u][i].second;

            // If the distance to v is shorter by going through u
            if(dist[v] > dist[u] + weight){

                dist[v]=dist[u]+weight;
                p.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}


// function to add vertice/edges in graph
void AddEdges(vector<vector<pair<int,int>>>& gr, int u, int v, int w){
    gr[u].push_back(make_pair(v,w));
    gr[v].push_back(make_pair(u,w));
}

int main(){

    // pair of node, weight
    vector<vector<pair<int,int>>> gr(9, vector<pair<int,int>>(9));

    AddEdges(gr,0,1,4);
    AddEdges(gr,0,7,8);
    AddEdges(gr,1,2,8);
    AddEdges(gr,1,7,11);
    AddEdges(gr,2,3,7);
    AddEdges(gr,2,8,2);
    AddEdges(gr,2,5,4);
    AddEdges(gr,3,4,9);
    AddEdges(gr,3,5,14);
    AddEdges(gr,4,5,10);
    AddEdges(gr,5,6,2);
    AddEdges(gr,6,7,1);
    AddEdges(gr,6,8,6);
    AddEdges(gr,7,8,7);

    vector<int> dist = dijkstra(gr,0);
    // print shortest distance stored in dist[]
    cout<<"Vertex Distance from source"<<endl;
    for(int i=0; i<9; i++){
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }

    return 0;
}


