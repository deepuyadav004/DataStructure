// based on unbounded knapsack

// Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

 

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.



int cutRod(int price[], int n) {
        
        int dp[n+1][n+1];
        for(int i=0; i<n+1; i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(i<=j){
                    dp[i][j]=max(price[i-1]+dp[i][j-i], dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
