// using bfs ( kahn's algo )

void topsort(vector<int> arr[], int n){

    // vector to store indegree of every node
    vector<int>in(n, 0);

    // calculating indegree of every node
    for(int i=0; i<n; i++){
        for(auto it:arr[i]){
            in[it]++;
        }
    }

    queue<int>q;
    // pushing all nodes with 0 indegree into queue
    for(int i=0; i<n; i++){
        if(in[i]==0){
            q.push(i);
        }
    }

    // running normal bfs call
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";

        for(auto it:arr[node]){
            in[it]--;
            if(in[it]==0){
                q.push(it);
            }
        }
    }
    cout<<endl;

}

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> arr[n+1];
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

    // topological sort using bfs (kahn's algo)
    topsort(arr, n);
    return 0;
}

