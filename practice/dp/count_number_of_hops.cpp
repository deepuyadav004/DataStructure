// GFG


A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1
Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step


// ---------------------------------------------------------------------- recursive --------------------------------------------------------------------------------

 long long countWays(int n)
    {
        
        // your code here
        if(n < 0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        
        return countWays(n-1)+countWays(n-2)+countWays(n-3);
        
        
    }

// ----------------------------------------------------------------------- using tables ----------------------------------------------------------------------------

Algorithm: 
Create an array of size n + 1 and initialize the first 3 variables with 1, 1, 2. The base cases.
Run a loop from 3 to n.
For each index i, compute value of ith position as dp[i] = dp[i-1] + dp[i-2] + dp[i-3].
Print the value of dp[n], as the Count of number of ways to cover a distance.



 long long countWays(int n)
    {
        
        // your code here
        if(n==0 || n==1){
            return 1;
        }
        long long dp[n+1];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3; i<=n; i++){
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%1000000007;
        }
        
        return dp[n];
        
    }

Complexity Analysis: 
Time Complexity: O(n). 
Only one traversal of the array is needed. So Time Complexity is O(n)
Space complexity: O(n). 
To store the values in a DP O(n) extra space is needed.

  
  //-------------------------------------------------------------------- more optimize way-------------------------------------------------------------------
  
    Algorithm:


Create an array of size 3 and initialize the values for step 0,1,2 as 1,1,2 (Base cases).
Run a loop from 3 to n(dist).
For each index compute the value as ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3] + ways[(i-3)%3] and store its value at i%3 index of array ways. If we are computing value for index 3 then the computed value will go at index 0 because for larger indices(4 ,5,6.....) we don't need the value of index 0.
Return the value of ways[n%3].
  
  
