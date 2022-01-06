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


//----------------------------------------------------------------------- memoization ----------------------------------------------------------------------------------


class Solution{
    int dp[201][201][2];
public:
    int countWays(int N, string S){
        // code here
        memset(dp, -1, sizeof(dp));
        return helper(S,0,N-1,1);
    }
    
    int helper(string s, int i, int j, int isTrue){
        if(i > j){
            return 0;
        }
        
        if(i == j){
            if(isTrue==1){
                return s[i]=='T' ? 1:0;
            }else{
                return s[i]=='F' ? 1:0;
            }
        }
        
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
        
        int ans=0;
        for(int k=i+1; k<j; k+=2){
            int lt=helper(s,i,k-1,1);
            int lf=helper(s,i,k-1,0);
            int rt=helper(s,k+1,j,1);
            int rf=helper(s,k+1,j,0);
            
            if(s[k]=='&'){
                if(isTrue==1){
                    ans+=lt*rt;
                }else{
                    ans+=lf*rf+lt*rf+lf*rt;
                }
            }else if(s[k]=='|'){
                if(isTrue==1){
                    ans+=lt*rt+lf*rt+lt*rf;
                }else{
                    ans+=lf*rf;
                }
            }else if(s[k]=='^'){
                if(isTrue==1){
                    ans+=lt*rf+lf*rt;
                }else{
                    ans+=lt*rt+lf*rf;
                }
            }
        }
        return dp[i][j][isTrue] = ans%1003;  // given in question description to return ans modulo 1003
    }
};



// int memoization instead of 3D matrix using map


class Solution{
    unordered_map<string, int>mp;
public:
    int countWays(int N, string S){
        // code here
        mp.clear();
        return helper(S,0,N-1,1);
    }
    
    int helper(string s, int i, int j, int isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue==1){
                return s[i]=='T'? 1:0;
            }else{
                return s[i]=='F' ? 1:0;
            }
        }
        string temp="";
        temp+=to_string(i);
        temp+=" ";
        temp+=to_string(j);
        temp+=" ";
        temp+=to_string(isTrue);
        
        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }
        
        int ans=0;
        for(int k=i+1; k<j; k+=2){
            int lt=helper(s,i,k-1,1);
            int lf=helper(s,i,k-1,0);
            int rt=helper(s,k+1,j,1);
            int rf=helper(s,k+1,j,0);
            
            if(s[k]=='&'){
                if(isTrue==1){
                    ans+=lt*rt;
                }else{
                    ans+=lf*rf+lt*rf+lf*rt;
                }
            }else if(s[k]=='|'){
                if(isTrue==1){
                    ans+=lt*rt+lf*rt+lt*rf;
                }else{
                    ans+=lf*rf;
                }
            }else if(s[k]=='^'){
                if(isTrue==1){
                    ans+=lt*rf+lf*rt;
                }else{
                    ans+=lt*rt+lf*rf;
                }
            }
        }
        return  mp[temp] = ans%1003;
    }
};
