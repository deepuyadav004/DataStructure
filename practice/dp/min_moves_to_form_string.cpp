GFG

Given a string S, check if it is possible to construct the given string S by performing any of the below operations any number of times. In each step, we can:

Add any character at the end of the string.
or, append the string to the string itself.
The above steps can be applied any number of times. The task is to find the minimum steps required to form the string.

Example 1:

Input: S = "aaaaaaaa"
Output: 4
Explanation: 
move 1: add 'a' to form "a"
move 2: add 'a' to form "aa"
move 3: append "aa" to form "aaaa"
move 4: append "aaaa" to form "aaaaaaaa"
  
  //                                    code 
  
  int minSteps(string S)
	{
		int n = S.size();

		int dp[n];

		// initializing dp[i] to INT_MAX
		for (int i = 0; i < n; i++)
			dp[i] = INT_MAX;

		// initialize both strings to null
		string s1 = "", s2 = "";

		// base case
		dp[0] = 1;

		s1 += S[0];

		for (int i = 1; i < n; i++) {
			s1 += S[i];

			// check if it can be appended
			s2 = S.substr(i + 1, i + 1);

			// addition of character takes one step
			dp[i] = min(dp[i], dp[i - 1] + 1);

			// appending takes 1 step, and we directly
			// reach index i*2+1 after appending
			// so the number of steps is stord in i*2+1
			if (s1 == s2)
				dp[i * 2 + 1] = min(dp[i] + 1, dp[i * 2 + 1]);
		}

		return dp[n - 1];
	}

//---------------------------------------------------------------------- memoization ---------------------------------------------------------------------------

