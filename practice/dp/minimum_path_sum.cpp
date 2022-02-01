Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
  
  
  class Solution {
public:
    int dp[202][202];
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m=grid.size();
        int n=grid[0].size();
        
        return helper(grid, m-1, n-1);
    }
    
    int helper(vector<vector<int>>grid, int m, int n){
        if(m<0 || n<0){
            return INT_MAX;
        }
        if(m==0 && n==0){
            return grid[m][n];
        }
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        return dp[m][n] = min(helper(grid,m-1,n), helper(grid, m, n-1))+grid[m][n];
    }
};

on submitting getting error time limit exceeded

//-------------------------------------------------- memoization with no error -------------------------------------------------------------------------------------

public:
    vector<vector<int>>dp;
    int m,n;
    int solve(vector<vector<int>>&grid,int m,int n,int i,int j)
    {
        if(i==m-1) 
        {
          int  sum1=0;
            for(int k=j;k<n;k++)
            {
               sum1=sum1+grid[m-1][k]; 
            }
            return sum1;
        }
         if(j==n-1) 
        {
          int  sum2=0;
            for(int k=i;k<m;k++)
            {
               sum2=sum2+grid[k][n-1]; 
            }
            return sum2;
        }
        else{ 
            if(dp[i][j]!=-1) return dp[i][j];
            else{
            dp[i][j]=min(grid[i][j]+solve(grid,m,n,i+1,j),grid[i][j]+solve(grid,m,n,i,j+1));
                return dp[i][j];
            }
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<int>temp(n+1,-1);
        dp.resize(m+1,temp);
        return solve(grid,m,n,0,0);
    }
};



//---------------------------------------------------------------------------- bottmom up-------------------------------------------------------------------------------

  int minPathSum(vector<vector<int>>& a) {
        int row = a.size();
        int col = a[0].size();
        vector<vector<int>> memo(row, vector<int> (col));
        //base case (last element)
        memo[row-1][col-1] = a[row-1][col-1];
        int lastcol = a[row-1][col-1];
        int lastrow = a[row-1][col-1];
        //base case (last row and last column)
        for(int i=row-2; i>=0; i--){
            memo[i][col-1] = a[i][col-1] + lastcol;
            lastcol+= a[i][col-1];
        }
        for(int j=col-2; j>=0; j--){
            lastrow+= a[row-1][j];
            memo[row-1][j]+= lastrow;
        }
        //filling up the memo
        for(int i=row-2; i>=0; i--){
            for(int j=col-2; j>=0; j--){
                //main logic
                memo[i][j] = a[i][j] + min(memo[i+1][j], memo[i][j+1]);
            }
        }
        return memo[0][0];
    }
    
    
    
  
  
