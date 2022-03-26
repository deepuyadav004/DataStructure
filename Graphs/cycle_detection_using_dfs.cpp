
bool cycle_using_dfs(vector<int> arr[], int n){
    vector<bool>visit(n+1, false);
    for(int i=1; i<=n; i++){
        if(!visit[i]){
            stack<pair<int, int>>st;
            st.push({i, -1});
            visit[i]=true;
            while(!st.empty()){
                int node=st.top().first;
                int parent=st.top().second;
                st.pop();
                for(auto it:arr[node]){
                    if(!visit[it]){
                        st.push({it, node});
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
