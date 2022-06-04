
#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin>>n>>m;
    vector<pair<int,int>>arr[n];
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        arr[u].push_back(make_pair(v, wt));
        arr[v].push_back(make_pair(u, wt));
    }

    int key[n];
    int parent[n];
    bool mst[n];
    for(int i = 0; i<n; i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    key[0]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    // min value int key array and node
    pq.push({0, 0});
    for(int i=0; i<n-1; i++){
        // int u = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;
        for(auto it : arr[u]){
            int v = it.first;
            int weight = it.second;
            if(mst[v]==false && weight < key[v]){
                parent[v]=u;
                key[v]=weight;
                pq.push({key[v], v});
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
    return 0;
}







