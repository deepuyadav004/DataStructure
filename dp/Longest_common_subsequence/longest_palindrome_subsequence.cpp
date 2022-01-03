// similar to lcs
// call lcs for given string and reverse of given string and return lcs


// Given a String, find the longest palindromic subsequence.


// Example 1:

// Input:
// S = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the
// longest subsequence which is also a palindrome.


 int longestPalinSubseq(string a) {
        //code here
        int x=a.length();
        string b=a;
        reverse(a.begin(), a.end());
        
        int dp[x+1][x+1];
        for(int i=0; i<=x; i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=x; j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[x][x];
    }
