// similar to lcs add i != j condition in if statement

// Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.

// Example 1:

// Input:
// str = "axxxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x x y 
// 0 1 2 3 4

// The longest subsequence is "xx". 
// It appears twice as explained below.

	int LongestRepeatingSubsequence(string str){
		    // Code here
		    string str2=str;
		    int x=str.length();
		    int dp[x+1][x+1];
		    
		    for(int i=0; i<=x; i++){
		        dp[i][0]=0;
		        dp[0][i]=0;
		    }
		    
		    for(int i=1; i<=x; i++){
		        for(int j=1; j<=x; j++){
		            if(str[i-1] == str2[j-1] && i != j){
		                dp[i][j]=dp[i-1][j-1]+1;
		            }else{
		                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    return dp[x][x];
		}
