LEETCPDE

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target.
  You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
  
  
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        vector<int>temp;
        vector<vector<int>>ans;
        
        helper(0, n, target, temp, ans, candidates);
        return ans;
    }
    
    void helper(int idx, int n, int target, vector<int>&temp, vector<vector<int>>& ans, vector<int> candidates){
        
        if(idx>=n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            helper(idx,n,target-candidates[idx], temp, ans, candidates);
            temp.pop_back();
        }
        helper(idx+1, n, target, temp, ans, candidates);
    }



//----------------------------------------------------------- combination sum 2-----------------------------------------------------------------------------------------

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
  

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

 vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        helper(0, target, temp, ans, candidates);
        return ans;
    }
    
    void helper(int idx, int target, vector<int>& temp, vector<vector<int>>& ans,vector<int> candidates){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            int curr=idx;
            // idx+=1;
            helper(idx+1, target-candidates[curr], temp, ans, candidates);
            temp.pop_back();
            
            while(idx+1<candidates.size() && candidates[idx]==candidates[idx+1]) idx++;
            
            
        }
        helper(idx+1, target, temp, ans, candidates);
        
        
    }
