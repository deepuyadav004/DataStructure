// https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
    int timer=1;
    vector<vector<int>>ans;
public:
    void helper(int node, int parent, vector<vector<int>>&gr, vector<int>&low, vector<int>&tm,          vector<int>&visit){
        visit[node]=1;
        low[node]=tm[node]=timer;
        timer++;
        for(auto it : gr[node]){
            if(it == parent) continue;
            if(!visit[it]){
                helper(it, node, gr, low, tm, visit);
                low[node]=min(low[node], low[it]);
                if(tm[node] < low[it]){
                    ans.push_back({it, node});
                }
            }else{
                low[node]=min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>gr(n);
        for(auto it : connections){
            gr[it[0]].push_back(it[1]);
            gr[it[1]].push_back(it[0]);
        }
        vector<int>low(n), tm(n), visit(n);
        helper(0, -1, gr, low, tm, visit);
        return ans;
    }
};
