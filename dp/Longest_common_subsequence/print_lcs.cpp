// same as lcs
// write code for lcs
// then in end instead of returning max length print lcs


#include<bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2, int x, int y){

    int dp[x+1][y+1];
    for(int i=0; i<=x; i++){
        dp[i][0]=0;
    }
    for(int j=0; j<=y; j++){
        dp[0][j]=0;
    }

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans="";
    int i=x;
    int j=y;
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){

    string s1="ABCDGH";
    string s2="AEDFHR";
    int x=6;
    int y=6;
    cout<<lcs(s1,s2,x,y)<<endl;
    return 0;
}
