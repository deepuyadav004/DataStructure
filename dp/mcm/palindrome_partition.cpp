// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.


// Example 1:

// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings 
// are "a", "babbbab", "b", "ababa".



// recursive code

 int palindromicPartition(string str)
    {
        // code here
        int j=str.length()-1;
        return helper(str,0,j);
    }
    
    int helper(string str, int i, int j){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(str,i,j)){
            return 0;
        }
        
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            int temp=helper(str,i,k)+helper(str,k+1,j)+1;
            ans=min(ans,temp);
        }
        
        return ans;
    }
    
    bool isPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }


//------------------------------------------------------------------- memoization ----------------------------------------------------------------------------------------


class Solution{
    int dp[501][501];
public:
    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int j=str.length()-1;
        return helper(str,0,j);
    }
    
    int helper(string str, int i, int j){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(str,i,j)){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            int temp=helper(str,i,k)+helper(str,k+1,j)+1;
            ans=min(ans,temp);
        }
        
        return dp[i][j] = ans;
    }
    
    bool isPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};



//-------------------------------------------------------------------- optimization of dp ----------------------------------------------------------------------------------


class Solution{
    int dp[501][501];
public:
    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int j=str.length()-1;
        return helper(str,0,j);
    }
    
    int helper(string str, int i, int j){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(str,i,j)){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        for(int k=i; k<j; k++){
            int left, right;
            // int temp=helper(str,i,k)+helper(str,k+1,j)+1;
            if(dp[i][k] != -1){
                left=dp[i][k];
            }else{
                left=helper(str,i,k);
            }
            
            if(dp[k+1][j] != -1){
                right=dp[k+1][j];
            }else{
                right=helper(str, k+1, j);
            }
            int temp=left+right+1;
            ans=min(ans,temp);
        }
        
        return dp[i][j] = ans;
    }
    
    bool isPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
