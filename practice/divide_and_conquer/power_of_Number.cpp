Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo 109 + 7.

Example 1:

Input:
N = 2
Output: 4
Explanation: The reverse of 2 is 2
and after raising power of 2 by 2 
we get 4 which gives remainder as 
4 by dividing 1000000007.
  
  long long modfun(long long n, long long R)
    {
        // Base cases 
        if (n == 0) 
            return 0; 
        // power zero mean answer is 1
        if (R == 0)  
            return 1; 
      
        long long y; 
        // If R is even 
        if (R % 2 == 0) { 
            // finding r/2 power as power is even then storing answer 
            // in y and if power is even like 2^4 we can simply do (2^2)*(2^2)
            y = modfun(n, R/2);  
            y = (y * y) % mod; 
        } 
      
        // If R is odd 
        else { 
            y = n % mod; 
            // reduce the power by 1 to make it even. The reducing power by one can be done if we take one 
            // n out.
            // Like 2^3 can be written as 2*(2^2)
            y = (y * modfun(n, R - 1) % mod) % mod; 
            
        } 
        // finally return the answer (y+mod)%mod = (y%mod+mod%mod)%mod = (y%mod)%mod
        return ((y + mod) % mod);  
    }
    
    
    long long power(int N,int R)
    {
        return modfun(N,R)%mod;
        
    }
