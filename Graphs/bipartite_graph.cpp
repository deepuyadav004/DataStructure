// using bfs iterative


bool checkBipartiteBFS(vector<int> arr[], int n){
    vector<int>color(n+1, -1);
    for(int i=1; i<=n; i++){
        if(color[i]==-1){
            queue<int>q;
            q.push(i);
            color[i]=1;

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(auto it:arr[node]){
                    if(color[it]==-1){
                        color[it]=1-color[node];
                        q.push(it);
                    }else if(color[it]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


// using dfs iterative


bool graph_colouring_dfs(vector<int> arr[], int n){
    vector<int> color(n+1, -1);
    for(int i=1; i<=n; i++){
        if(color[i]==-1){
            color[i]=1;
            stack<int>st;
            st.push(i);

            while(!st.empty()){
                int node=st.top();
                st.pop();

                for(auto it:arr[node]){
                    if(color[it]==-1){
                        color[it]=1-color[node];
                        st.push(it);
                    }else if(color[it]==color[node]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
