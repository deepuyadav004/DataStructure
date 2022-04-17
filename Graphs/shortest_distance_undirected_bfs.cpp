#include<bits/stdc++.h>
using namespace std;

// shortest distance between src and all other nodees using bfs
void shortest_distance(vector<int> arr[], int n, int src){

    // dis array to store distance of each node from src
    int dis[n];
    // initialize dis array with int_max
    for(int i=0; i<n; i++){
        dis[i]=INT_MAX;
    }

    queue<int>q;
    q.push(src);
    // dis of src from src is zero
    dis[src]=0;


    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it:arr[node]){

            // if distance throught node is smaller than current dis update distance
            if(dis[node]+1 < dis[it]){
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<"Distance between "<<src<<" and "<<i<<" is :- "<<dis[i]<<endl;
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int>arr[n];
    for(int i=0; i<m; i++ ){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        cout<<i<<" :- ";
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    // shortest distance between src and all other nodes using bfs
    shortest_distance(arr, n, 0);
    return 0;
}

