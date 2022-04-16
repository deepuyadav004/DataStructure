
// cycle detection in directed graph using kahn's algo
bool isCyclePresent(vector<int> arr[], int n){
    vector<int>in(n,0);
    for(int i=0; i<n; i++){
        for(auto it:arr[i]){
            in[it]++;
        }
    }

    queue<int>q;
    for(int i=0; i<n; i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;

        for(auto it:arr[node]){
            in[it]--;
            if(in[it]==0){
                q.push(it);
            }
        }
    }
    if(cnt==n) return false;
    return true;
}
