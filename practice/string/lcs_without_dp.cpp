Given two strings A and B, find if A is a subsequence of B.

Example 1:

Input:
A = AXY 
B = YADXCP
Output: 0 
Explanation: A is not a subsequence of B
as 'Y' appears before 'A'.
  
  
   bool isSubSequence(string A, string B) 
    {
        // code here
        int i=0, j=0;
        while(i<A.length() and j<B.length()){
            if(A[i]==B[j]){
                i++;
            }
            j++;
        }
        return i==A.length();
    }
