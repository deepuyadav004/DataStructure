// variation of lcs
// in end return x+y-2*lcs

// Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

// Example 1:

// Input: str1 = "heap", str2 = "pea"
// Output: 3
// Explanation: 2 deletions and 1 insertion
// p and h deleted from heap. Then, p is 
// inserted at the beginning One thing to 
// note, though p was required yet it was 
// removed/deleted first from its position 
// and then it is inserted to some other 
// position. Thus, p contributes one to the 
// deletion_count and one to the 
// insertion_count.

	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
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
	    
	    return x+y-2*dp[x][y];
	    
	}
