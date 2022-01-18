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
