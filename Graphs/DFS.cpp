
// Deapth for search (DFS)
// Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
// Space Complexity: O(V). 
// Since an extra visited array is needed of size V.


#include<bits/stdc++.h>
using namespace std;

void AddEdge(vector<int> gr[], int u, int v){
    gr[u].emplace_back(v);
    gr[v].emplace_back(u);

}

// Iterative method for DFS
void dfs_iterative(vector<int> gr[], int start){
    vector<bool> visited(gr->size(), false);
    stack<int> st;
    st.push(start);
    visited[start]=true;
    while(!st.empty()){
        int v=st.top();
        st.pop();
        cout<<v<<" ";

        // push all neighbours of current edge in stack
        for(auto i=gr[v].begin(); i!=gr[v].end(); i++){
            if(!visited[*i]){
                st.push(*i);
                visited[*i]=true;
            }
        }
    }
}

// DFS Recursive
void dfs_recursive(vector<int> gr[], vector<bool> &visited, int node){

    visited[node]=true;
    cout<<node<<" ";
    for(auto i=gr[node].begin(); i!=gr[node].end(); i++){
        if(!visited[*i]){
            dfs_recursive(gr,visited,*i);
        }
    }
}

int main(){

    int n=10;
    vector<int> gr[n];
    AddEdge(gr,0,6);
    AddEdge(gr,0,7);
    AddEdge(gr,1,6);
    AddEdge(gr,1,4);
    AddEdge(gr,2,4);
    AddEdge(gr,2,3);
    AddEdge(gr,3,8);
    AddEdge(gr,5,9);
    AddEdge(gr,5,8);
    AddEdge(gr,6,5);
    AddEdge(gr,7,9);

    cout<<"DFS Iterative"<<endl;
    dfs_iterative(gr,0);
    cout<<endl;

    cout<<"DFS Recursive"<<endl;
    vector<bool> visited(gr->size(), false);
    dfs_recursive(gr,visited,0);

    return 0;
}

