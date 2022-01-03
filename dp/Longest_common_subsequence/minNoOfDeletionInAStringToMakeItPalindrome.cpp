// similar to lps(which is similar to lcs)
//   int end return length of given string - length of lps

// Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
// Note: The order of characters should be maintained.

// Example 1:

// Input: n = 7, str = "aebcbda"
// Output: 2
// Explanation: We'll remove 'e' and
// 'd' and the string become "abcba".

int minDeletions(string str, int n) { 
    //complete the function here 
    string str2=str;
    reverse(str.begin(), str.end());
    
    int dp[n+1][n+1];
    for(int i=0; i<=n; i++){
        dp[0][i]=0;
        dp[i][0]=0;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(str[i-1] == str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
} 
