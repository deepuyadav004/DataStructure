
// BFS 


#include<bits/stdc++.h>
using namespace std;

void eddEdge(vector<int> gr[], int u, int v){
    gr[u].emplace_back(v);
    gr[v].emplace_back(u);
}

void bfs(vector<int> gr[], int strt){
    vector<bool> visited(gr->size(), false);
    queue<int> kt;
    kt.push(strt);
    visited[strt]=true;
    while(!kt.empty()){
        int v=kt.front();
        cout<<v<<" ";
        kt.pop();
        
        // Enqueue all adjacent nodes of v and mark them visited
        for(auto i=gr[v].begin(); i!=gr[v].end(); i++){
            if(!visited[*i]){
                kt.push(*i);
                visited[*i]=true;
            }
        }
    }
}

int main(){
    int v=7; //vertices
    vector<int> gr[v];

    eddEdge(gr,0,1);
    eddEdge(gr,0,3);
    eddEdge(gr,1,2);
    eddEdge(gr,2,3);
    eddEdge(gr,2,6);
    eddEdge(gr,3,4);
    eddEdge(gr,4,5);
    eddEdge(gr,5,6);
    cout<<"BFS traversal starting from node 0"<<endl;
    bfs(gr,0);

    return 0;
}
