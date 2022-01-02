// similar to lcs
// initilaziation is same as lcs

// only in else conditio dp[i][j]=0

// Given two strings. The task is to find the length of the longest common substring.


// Example 1:

// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.

 int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        
        // initilization is same as lcs
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int j=0; j<=m; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
