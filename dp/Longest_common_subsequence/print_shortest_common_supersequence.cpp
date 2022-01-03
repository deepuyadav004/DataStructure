// similar to print lcs with minor changes

// Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

// A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

// Example 1:

// Input: str1 = "abac", str2 = "cab"
// Output: "cabac"
// Explanation: 
// str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
// str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
// The answer provided is the shortest such string that satisfies these properties.


string shortestCommonSupersequence(string str1, string str2) {
        int x=str1.length();
        int y=str2.length();
        
        int dp[x+1][y+1];
        for(int i=0; i<=x; i++){
            dp[i][0]=0;
        }
        for(int j=0; j<=y; j++){
            dp[0][j]=0;
        }
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i=x;
        int j=y;
        
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans+=str1[i-1];
                    i--;
                }else{
                    ans+=str2[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
