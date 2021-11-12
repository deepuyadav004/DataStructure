// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.



int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        
        if(n1==0 || n2==0){
            return 0;
        }
        
        int res[n1+1][n2+1];
        for(int i=0; i<=n1; i++){
            res[i][0]=0;
        }
        for(int j=0; j<=n2; j++){
            res[0][j]=0;
        }
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1]==text2[j-1]){
                    res[i][j]=res[i-1][j-1]+1;
                }else{
                    res[i][j]=max(res[i-1][j], res[i][j-1]);
                }
            }
        }
        return res[n1][n2];
    }
