// Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


// Example 1:

// Input: V = 30, M = 3, coins[] = {25, 10, 5}
// Output: 2
// Explanation: Use one 25 cent coin
// and one 5 cent coin

	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[M+1][V+1];
	    memset(dp, -1, sizeof(dp));
	    for(int i=0; i<=M; i++){
	        dp[i][0]=0;
	    }
	    for(int j=0; j<=V; j++){
	        dp[0][j]=INT_MAX-1;
	    }
	    
	    for(int i=1; i<=M; i++){
	        for(int j=1; j<=V; j++){
	            if(coins[i-1] <= j){
	                dp[i][j]=min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    return (dp[M][V]==INT_MAX-1) ? -1:dp[M][V];
	} 
