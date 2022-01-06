// Given a boolean expression S of length N with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

 

// Example 1:

// Input: N = 7
// S = T|T&F^T
// Output: 4
// Explaination: The expression evaluates 
// to true in 4 ways ((T|T)&(F^T)), 
// (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).



//------------------------------------------------------------------------------------recursive approach------------------------------------------------------------------------


class Solution{
public:
    int countWays(int N, string S){
        // code here
        return solve(S,0,N-1,1);
    }
    
    int solve(string s, int i, int j, int isTrue){
        if(i > j){
            return 0;
        }
        if(i==j){
            if(isTrue == 1){
                return s[i]=='T' ? 1:0;
            }else{
                return s[i]=='F' ? 1:0;
            }
        }
        
        int ans=0;
        for(int k=i+1; k<j; k+=2){
            int lt=solve(s,i,k-1,1);
            int lf=solve(s,i,k-1,0);
            int rt=solve(s,k+1,j,1);
            int rf=solve(s,k+1,j,0);
            
            if(s[k]=='&'){
                if(isTrue==1){
                    ans+=lt*rt;
                }else{
                    ans+=lt*rf+lf*rt+lf*rf;
                }
            }else if(s[k]=='|'){
                if(isTrue==1){
                    ans+=lt*rt+lt*rf+rt*lf;
                }else{
                    ans+=lf*rf;
                }
            }else if(s[k]=='^'){
                if(isTrue==1){
                    ans+=lf*rt+lt*rf;
                }else{
                    ans+=rt*lt+rf*rt;
                }
            }
        }
        return ans;
    }
};


//
