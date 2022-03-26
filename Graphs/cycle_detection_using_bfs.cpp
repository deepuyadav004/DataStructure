
bool cycle(vector<int> arr[], int n){
    vector<bool>visit(n+1, false);
    for(int i=1; i<=n; i++){
        if(!visit[i]){
            queue<pair<int,int>>q;
            q.push({i,-1});
            visit[i]=true;
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();

                for(auto it:arr[node]){
                    if(!visit[it]){
                        q.push({it, node});
                        visit[it]=true;
                    }else if(parent != it){
                        return true;
                    }
                }
            }           
        }
    }
    return false;
}
