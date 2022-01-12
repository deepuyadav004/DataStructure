Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.


Example 1:

Input: N = 7
A[] = {10, 9, 4, 5, 4, 8, 6}
Output: 3
Explaination: The three possible subsequences 
{10, 9, 8} , {4, 5, 4} and {4, 5, 6}.







int longestSubsequence(int N, int A[])
    {
        // Initializing the dp array
        int dp[N];
        for(int i = 0;i < N;i++)
            dp[i] = 1;
        
        // Calculating longest subsequence with adjacent elements having 
        // difference of 1
        for(int i = 1;i < N;i++){
            for(int j = 0;j < i;j++){
                if(abs(A[i] - A[j]) == 1)
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        
        // calculating the answer
        int ans = 1;
        for(int i = 0;i < N;i++)
            ans = max(ans, dp[i]);
        
        return ans;
    }
